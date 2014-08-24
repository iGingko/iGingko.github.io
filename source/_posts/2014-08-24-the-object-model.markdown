---
layout: post
title: "the-object-model"
date: 2014-08-24 15:40:45 +0800
comments: true
categories: 
---

# Objective-C对象模型

##前言
通过对Runtime的[开源代码](http://www.opensource.apple.com/tarballs/objc4/)的分析，得出Objective-C的对象模型的实现细节，以及Objective-C语言对象中对`isa swizzling`和`method swizzling`的支持。

##概述
> - Objective-C是一门面向对象，并且在C的基础上加入了Smalltalk式的消息机制而形成的编程语言，是C的超级，它主要被苹果公司用于开发Mac OS X和iOS操作系统。
- Objective-C是C的扩展，设计思路上借鉴了Smalltalk的面向对象和消息机制的思想。从我个人使用过的面向对象语言来看Objc是对消息传递支持的最彻底也最显式的。其它的C++、Java、Python、Ruby都体现的不明显，更倾向于对象的封装和抽象.
- Objc和C++基本上是两门语言，没有太大的关系。Objc本身是静态语言，编译后就是机器码，执行效率很高，但引入了很多类似Python、Ruby的动态特性，像动态类型推断，id，selector，block等特性，所以又非常灵活。
-用惯了Java或C++会觉得Objc的语法很怪，但是放空自己去学习这门语言的话，你会很快爱上它的消息式的编程风格，加上强悍的XCode，无论是写mac应用还是ios应用，都会非常得心应手。 

##苹果为什么会选择Objective-C
关于苹果为什么采用Ojbc的问题，说明一下，其实不是苹果采用了Objc，而是乔布斯创建的Next公司的操作系统NextStep采用了Ojbc作为原生语言。NextStep是以Mach和BSD为基础，Objc是其语言和运行库，后来的事大家都清楚，苹果买了NextStep，乔帮主回归，NextStep也成了Max OS X的基础。以后发展越来越好，Objc反而成了Apple的当家语言，现在基本上是Apple在维护Objc的发展。

##通过源代码分析OC对象模型

###Objective-C类和对象的声明
    //objc.h
    typedef struct objc_class *Class;//代表类 Objective-C class
    typedef struct objc_object *id;//代表对象，也就是类的实例 instance of a class.

    //NSObject.h -- NSProxy.h
    @interface NSObject <NSObject> {
        Class isa  OBJC_ISA_AVAILABILITY;
    }
    
> - 对象中的数据组成形式为isa varFromGrandFather varFromFather VarFromSon
- 从内存形式上看，对象内的成员变量，是从祖类继承而来，在对象内部生成副本
- 从对象的内存组织上来看，对象本身不关心行为(对象的方法或实例方法)，重点都在数据组织上
- isa是一个指针,指向了该对象的类.实质上,同一个类的实例,都指向同一个类对象(类也是一种特殊对象).类中包含了实例方法,也就是说,同一个类的所有实例共用了这些实例方法.消息就是发送给对象,对象转交给其isa指向类去处理
- Objective-C的这种设计,既可以友好地实现面向对象,又可以有效地节约内存.降低冗余数据.对象对方法的调用是通过isa间接去调用,这样就造成了方法调用的动态性
- 一个对象并不晓得它能否应答一个方法,它本身既不包含方法的实现,也不包含有方法的指针,而是间接通过isa转到自己的类才能知道
- 类中的实例方法是以链表形式存在,运行时候,可以修改链表中的实例方法,即可以增删改查,这与C中的函数默认都是extern的不同

#####Runtime.h中OC类和对象的声明
    
    //runtime.h
    struct objc_object {
        Class isa  OBJC_ISA_AVAILABILITY;
        //struct objc_class *isa;
        //varFromGrandFather
        //varFromFather
        //VarFromSon
    };
    /*
    这是由编译器为每个类产生的数据结构,这个结构定义了一个类.这个结构是通过编译器在执行时产生,在运行时发    送消息时使用.因此,一些成员改变了类型.编译器产生"char* const"类型的字符串指针替代了下面的成员变量    "super_class"
    */
    struct objc_class {
        Class isa  OBJC_ISA_AVAILABILITY;
        //struct objc_class *isa;
    };

在objc.h里，声明了两个类型：`Class`和`id`,分别代表`类`和`实例对象`,可以看作是泛型。
在Runtime.h里，我们看到OC类和对象其实就是两个结构体，其中第一个变量就是一个指向自己所属类的`isa`指针
> 在OC中，一个对象的类由它的isa指针决定，isa指针指向这个对象所属的Class.或者可以这么说:*凡是地址是isa指针的结构体，都可以看做OC类*

### Objective-C类和对象的定义
#### objc-private.h 这里定义了OC对象
    //objc-private.h
    struct objc_object {
    private:
        uintptr_t isa; //isa 指针，如果不是TaggedPointer，指向 Class

    public:

        // ISA() assumes this is NOT a tagged pointer object
        Class ISA()
        {
            assert(!isTaggedPointer());
            return (Class)isa;
        }

        // getIsa() allows this to be a tagged pointer object
        Class getIsa()
        {
    #if SUPPORT_TAGGED_POINTERS
            if (isTaggedPointer()) {
                uintptr_t slot =
                    ((uintptr_t)this >> TAG_SLOT_SHIFT) & TAG_SLOT_MASK;
                return objc_tag_classes[slot];
            }
    #endif
            return ISA();
        }

        // changeIsa() should be used to change the isa of existing objects.
        // If this is a new object, use initIsa() for performance.
        Class changeIsa(Class cls);

        // initIsa() should be used to init the isa of new objects only.
        // If this object already has an isa, use changeIsa() for correctness.
        void initIsa(Class cls)
        {
            assert(!isTaggedPointer());
            isa = (uintptr_t)cls;
        }

        bool isTaggedPointer()
        {
    #if SUPPORT_TAGGED_POINTERS
            return ((uintptr_t)this & TAG_MASK);
    #else
            return false;
    #endif
        }
    };
    
#### objc-runtime-new.h 这里定义了OC类
    //objc-runtime-new.h
    struct objc_class : objc_object {
        // Class ISA;
        Class superclass;
        cache_t cache;
        uintptr_t data_NEVER_USE;
        /*....省略若干方法...*/
    };
>一般程序语言，对象的尽头都是自己生了自己，自己下个蛋，爬出来了自己。似乎是个悖论，但确实如此。作为根类的NSObject就是这样一个家伙

![Alt text](/images/posts/struct.png)

- super_class 指向父类的指针.因为Objective-C借鉴了SimTALK,在类的继承实现上,是通过一条继承链实现的.super_class就是整个继承链的核心字段.
- name 类的名字
- version 版本
- info 信息
- instance_size 实例的内存大小
- ivars  是一个指向实例变量列表的指针
- methodLists       是一个指向实例方法列表的指针
- cache 缓存了常用的实例方法
- protools 是一个指向协议列表的指针

>我们知道,在Objective-C中,我们一般的定义形式是声明一个类的实例变量,属性,实例方法和类方法.并不能声明类变量.所以一般而言类对象的数据形式就是如上图的那些固定的字段.方法、属性和协议都存储在类定义的可写字段中，这些信息可以在运行时被改变。ivar存储在只读段，所以不能修改



##OC对象模型分析

- 从OC类的定义中可以看出，OC的类继承自OC对象，每个类也有一个`isa`指针，每个类也能接收消息。例如:`[NSObject alloc]`,就是在向NSObject这个类发送名为`alloc`的消息，所以每个类也可以看做是一个对象。那么类也必须是另一个类的实例，这个类就是元类(`metaclass`).
- 就像类保存了实例对象的方法列表一样，元类也保存了类的方法列表缓存`cache_t cache`，方法cache是为了提高访问效率而设定的，用来缓存调用过的方法，这样下次再调用的时候就能提高查找效率。
- 元类(`metaclass`)也是一个对象，那么原来的对象指向哪里呢？为了设计上的完整，所有的元类的isa指针都指向一个根元类(`root metaclass`).根元类（root metaclass）本身的isa指向自己，这样就形成了一个闭环。在实际编程中，我们几乎不会遇到向元类发消息的情况，那它的isa指针在实际上很少用到。不过这么设计保证了面向对象的干净，即所有事物都是对象，都有isa指针。
- 我们再来看看继承关系，由于类方法的定义是保存在元类(metaclass)中，而方法调用的规则是，如果该类没有一个方法的实现，则向它的父类继续查找。所以，为了保证父类的类方法可以在子类中可以被调用，所以子类的元类会继承父类的元类，换而言之，类对象和元类对象有着同样的继承关系。

- ![Alt text](/images/posts/class.png)

根据上图，我们可以看到以下几点：
- Root Class是指NSObject
- NSObject类包括它的对象实例方法
- NSObject的元类(q其实也就是根元类，这比较特殊)包括它的类方法，例如alloc方法
- NSObject的元类继承自NSObject类
- 创建一个OC类其实是创建一个类对（ClassPair）－类和元类，类的isa指针指向元类，元类的isa指向根元类，即图中的NSObject元类，根元类的isa指向它自己，形成闭环，保证isa指针永远不会为空 —同时这也会使得一个类（Class）可以 响应NSObject的所有实例方法
- isa指针指向就是消息传递的方向，通过isa指针没找到的消息，则继续通过superClass指针查找
- 对象中含有`实例变量`，类中含有`实例方法列表`，元类中含有`类方法列表`；NSobject的元类的superClass指向NSobject实例，所以理论上给元类发消息，能找到NSObject的实例方法，但我们在实际中很少用到

### 为什么要有元类
1. 可以分离类方法和实例方法
2. 元类总是会保证Class对象会从基类继承所有的实例和类方法


### 成员变量的不可变与方法的可变

Q:`为什么对象不能添加成员变量？`
A:因为对象在内存中的排布可以看成一个结构体，该结构体的大小不能动态变化，所以无法在运行时动态给对象增加成员变量

相对的，对象的方法定义都保存在类的可变区域中。Objective-C 2.0并未在头文件中将实现暴露出来，但在Objective-C 1.0中，我们可以看到方法的定义列表是一个名为`methodLists`的指针的指针（详见类的结构图)。通过修改该指针指向的指针的值，就可以实现动态地为某一个类增加成员方法。这也是Category实现的原理。同时也说明了为什么`Category`只可为对象增加成员方法，却不能增加成员变量。

需要特别说明一下，通过objc_setAssociatedObject 和 objc_getAssociatedObject方法可以变相地给对象增加成员变量，但由于实现机制不一样，所以并不是真正改变了对象的内存结构。

### isa-swizzling 在运行时动态创建一个类

**修改类的isa被称为isa-swizzling技术。isa-swizzling就是类型混合指针机制。KVO主要通过isa-swizzling，来实现其内部查找定位的。**

>KVO（key－value observer）就是通过isa swizzling来实现的。 当我们为一个类的某个属性添加observer时候，框架自动创建这个类的一个子类，并且修改这个类的isa指向这个新的子类。 由于在ios中函数调用都是转化为isa查表形式，所以这次查得时新的子类的表， 也就是说对类的函数调用被子类给拦截了，在拦截的实现中就可以通知observer了。


动态创建一个类需要三个步骤
> 1. 为“class pair”－类和元类 创建存储空间（使用 objc_allocateClassPair).
2. 为这个类添加所需的 methods 和 ivars（使用 class_addMethod).
3. 注册这个类，然后就可以使用了（使用 objc_registerClassPair).

下面的代码在运行时创建了一个 NSError 的子类同时为它添加了一个方法：
    
    Class newClass =
        objc_allocateClassPair([NSError class], "RuntimeErrorSubclass", 0);
    class_addMethod(newClass, @selector(report), (IMP)ReportFunction, "v@:");
    objc_registerClassPair(newClass);
    
添加的方法使用叫ReportFunction 的函数作为实现，定义如下：

    void ReportFunction(id self, SEL _cmd)
    {
        NSLog(@"This object is %p.", self);
        NSLog(@"Class is %@, and super is %@.", [self class], [self superclass]);

        Class currentClass = [self class];
        for (int i = 1; i < 5; i++)
        {
            NSLog(@"Following the isa pointer %d times gives %p", i, currentClass);
            currentClass = object_getClass(currentClass);
        }

        NSLog(@"NSObject's class is %p", [NSObject class]);
        NSLog(@"NSObject's meta class is %p", object_getClass([NSObject class]));
    }
    
### Method Swizzling (方法调配)
Objective-C提供了以下API来动态替换类方法或实例方法的实现：
- `class_replaceMethod` 替换类方法的定义
- `method_exchangeImplementations` 交换2个方法的实现
- `method_setImplementation` 设置1个方法的实现

上面三个方法的差别:

- `class_replaceMethod` ,有两种不同的行为。当类中没有想替换的原方法时，该方法会调用`class_addMethod`来为该类增加一个方法，也因为如此，`class_replaceMethod`在调用时需要传入types参数，而`method_exchangeImplementations`和`method_setImplementation`却不需要。
- method_exchangeImplementations 的内部实现相当于调用了2次method_setImplementation方法。

总结一下3个API的使用场景:
- `class_replaceMethod`, 当需要替换的方法可能有不存在的情况时，可以考虑使用该方法。
- `method_exchangeImplementations`，当需要交换2个方法的实现时使用。
- `method_setImplementation` 最简单的用法，当仅仅需要为一个方法设置其实现方式时使用。
- `ckass_getInstanceMethod` 根据给定的选择从类中抽取与之相关的方法

### 用Method-Swizzling 调试“黑盒方法”
selector名称对应的方法可以在运行期改变。类的方法列表会把选择子的名称映射到相关的方法实现上，使得“动态消息派发系统”能根据此找到应该调用的方法。这些方法均以函数指针的形式来表示，这种指针叫做IMP,原型如下：`id(*IMP)(id,SEL,……)`
#####实现两个方法的交换
    Method originalMethod = class_getInstanceMethond([NSString class],@selector(lowercasestring));
    Method swappedMethod = class_getInstanceMethod([NSString class],@selector(uppercaseString));
    method_exchangeImplementations(originalMethod,swappedMethod);

然后在实际应用中，像这样直接交换两个方法实现的意义并不大。但是可以通过这一手段来为既有的方法实现新增功能.比如在调用lowercaseString时记录某些信息。

    @interface NSString (EOCMyAdditions)
    - (NSString *)eoc_myLoercaseString;
    @end
    
    @implementation NSString (EOCMyAdditions)

    - (NSString *)eoc_myLoercaseString{
    NSString *lowercase = [self eoc_myLoercaseString];
    NSLog(@"%@ = > %@",self,lowercase);
    
    return lowercase;
    }

    @end
    
使用时情况如下:

    Method originalMethod = class_getInstanceMethod([NSString class], @selector(lowercaseString));
    Method swappedMethod  = class_getInstanceMethod([NSString class], @selector(eoc_myLoercaseString));
    method_exchangeImplementations(originalMethod, swappedMethod);
    NSString *testStr = @"Hello World";
    NSString *lowercaseString = [testStr lowercaseString];
    NSLog(@"%@",lowercaseString);

