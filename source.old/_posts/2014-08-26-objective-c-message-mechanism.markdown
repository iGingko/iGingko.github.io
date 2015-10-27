---
layout: post
title: "objective-c的消息机制"
date: 2014-08-26 16:46:15 +0800
comments: true
categories:
---


###前言

Ojbective-C的语法设计主要基于Smalltalk，除了提供传统的面向对象编程特性之外，还增加了很多类似动态语言Ruby、Python才具有的特性，例如动态类型、动态加载、动态绑定等等，同时强化了消息传递机制和表意（Intention Revealing Interface）接口的概念。

### 理解Objective-C 运行时消息机制的几个比较重要的概念

- `isa指针`:isa指针指向这个对象所属的Class.
- `methodLists`: 是一个指向实例方法列表的指针
- `cache` :缓存了常用的实例方
- `Method` **定义**对象方法和类方法。这个类型提供了方法的名字(就是**选择器**)、参数数量和类型，以及返回值（这些信息合起来成为方法的签名），还有一个指向代码的指针(IMP 也就是方法的实现)
- `SEL` 定义选择器。选择器是方法名的唯一标示符。
- `IMP` 定义方法的实现。这只是一个指向某个函数的指针，该函数接受一个对象、一个选择器和一个可变长参数列表，返回一个对象：`typedef id (*IMP)(id,SEL,...)`

### C语言中的“静态绑定”与简单“动态绑定“实现

由于OC是C的超集，所以最好是先理解C语言的调用方式。C语言使用*静态绑定*，也就是说，在编译期就能决定运行时所应调用的函数。以下列代码为例：
    #import <stdio.h>

    void printHello() {
	printf("Hello,World!");
    }

    void printGoodbye(){
	printf("Goodbye,World!");
    }

    void doTheThing(int type){
	if(type == 0){
	    printHello();
	}else {
	    printGoodbye();
	}
	return 0;
    }


上面代码中，如果不考虑"内联"，那么编译器在编译代码的时候就已经知道程序中有printHello和printGoodbye这两个函数了，于是会直接生成调用这些函数的指令。而函数地址实际上是**硬编码**在指令之中的。再看看下面的代码呢？
    #import <stdio.h>

    void printHello() {
	printf("Hello,World!");
    }

    void printGoodbye(){
	printf("Goodbye,World!");
    }

    void doTheThing(int type){
	void (*fnc)();
	if(type == 0){
	    fnc = printHello;
	}else {
	    fnc = printGoodbye;
	}

	fnc();
	return 0;
    }

这时使用的就是**动态绑定**了，因为所要调用的函数直到运行期才能确定。当然真正的Runtime要复杂得多，而上面只是一个简单的实现说明而已。
> 在Objective-C中，如果向某个对象传递消息，那就会使用**动态绑定**机制来决定需要调用的方法。在底层，所有方法都是普通的C语言函数，然而对象受到消息后，究竟调用哪个方法完全由运行期决定，甚至可以在运行时改变，这使得Obhective-C成为一门真正动态的语言。

### 动态绑定的全过程

给对象发送消息可以这样来写：

    id = [someObject messageName:parameter];//[reciever message];

在上面的例子中，someObject叫做reciever,messageName叫做selector，selector和参数合起来成为message.

动态绑定过程如下：
1. 编译器看到消息，转换为objc_msgSend这个标准的C语言函数。其原型为：

	void objc_msgSend(id self,SEL cmd,...)
这个是参数可变的函数，能接受两个或两个以上的参数。第一个参数代表接收者，第二个参数代表选择子(SEL是选择子的类型)，后续参数就是消息中的参数，其顺序不变。selector指的就是方法的名称
2. objc_msgSend 会依据`SEL`在接收者所属的类中搜索`methodlists`
3. 如果找到相应的`Method`,那么就会根据`IMP`,跳转至方法实现。如果找不到，那就沿着继承体系向上查找，找到合适的再跳转。
4. 如果最终找不到，就会执行`消息转发`

##### 在整个过程中有三点需要另外注意：
- 每个类中都有一个方法缓存列表(`cache`),在调用完成一个方法后，会将匹配结果进行缓存，下次执行就会很快了。
- Objective-C的方法可视为简单的C函数，其原型如下：

	<return_type> class_selector(id self,SEL _cmd,...)
你会发现，原型的样子和objc_msgSend函数很像，这不是巧合，而是为了利用**`尾调优化技术`**
>如果函数的最后一项操作是条用另外一个函数，那么就可以利`尾调优化`技术。编译器会生成跳转至另一个函数所需的指令，而且不会向调用堆栈中推入新的`栈帧(frame stack)`。只有当某函数的最后一项操作仅仅是调用其他函数而不会将其返回值另作他用的时候，才能执行`尾调优化`。如果不这么做的话，每次调用方法，都需要为调用objc_msgSend函数准备`栈帧`，大家都可以看到在`栈追踪(stack trace)`中看到这种栈帧，而且还会过早的`栈溢出(stack overflow)`
- 当待发的消息返回结构体，那么交由`obje_msgSend_stret`处理。发的消息返回浮点数，交由`objc_msgSend_fpret`处理。如果发消息给超类 [super message:para],那么交由`objc_msgSendSuper`处理。

###消息转发
当对象接收到无法解读的消息后，就会启动`消息转发(message forwarding)`,开发者在编写自己的类时，可于转发过程中设置挂钩，用以执行特定的逻辑，而不使程序崩溃或者做其他处理。

消息转发可分为两大阶段:
1. 第一阶段为动态方法解析。先征询接收者，所属的类，看其是否能动态添加方法，以处理当前这个“未知的选择子”(unknown selector),这叫做“动态方法解析”(dynamic method resolution)
2. 第二阶段涉及“完整的消息转发机制”(full forwarding mechanism)。如 果运行期系统已经把第一阶段执行完了,那么接收者自己就无法再以动态新增方法的手段来 响应包含该选择子的消息了。此时,运行期系统会请求接收者以其他手段来处理与消息相关 的方法调用。这又细分为两小步。首先,请接收者看看有没有其他对象能处理这条消息。若 有,则运行期系统会把消息转给那个对象,于是消息转发过程结束,一切如常。若没有“备 援的接收者”(replacement receiver),则启动完整的消息转发机制,运行期系统会把与消息有 关的全部细节都封装到 NSInvocation 对象中,再给接收者最后一次机会,令其设法解决当前 还未处理的这条消息。

####动态方法解析
对象在收到无法解读的消息后,首先将调用其所属类的下列类方法:

    + (BOOL)resolveInstanceMethod:(SEL)selector
如果尚未实现的方法为类方法，那么就会调用另外一个方法:
    + (BOOL)resolveClassMethod:(SEL)selector

使用这种办法的前提是:相关方法的实现代码已经写好,只等着运行的时候动态插在类 里面就可以了。此方案常用来实现 @dynamic 属性,比如说,要访问 CoreData 框架中 NSManagedObjects 对象的属性时就可以这么做,因为实现这些属性所需的存取方法 在编译期就能确定。
下列代码演示了如何用“resolveInstanceMethod:”来实现 @dynamic 属性: id autoDictionaryGetter(id self, SEL _cmd);
void autoDictionarySetter(id self, SEL _cmd, id value);
    + (BOOL)resolveInstanceMethod:(SEL)selector {
    NSString *selectorString = NSStringFromSelector(selector); if ( /* selector is from a @dynamic property */ ) {
    if ([selectorString hasPrefix:@"set"]) { class_addMethod(self,selector, (IMP)autoDictionarySetter, "v@:@");
    } else {
	class_addMethod(self,selector, (IMP)autoDictionaryGetter, "@@:");
    }
	return YES;
    }
	return [super resolveInstanceMethod:selector];
    }
首先将选择子化为字符串,然后检测其是否表示设置方法。若前缀为 set,则表示设置 方法,否则就是获取方法。不管哪种情况,都会把处理该选择子的方法加到类里面,所添加 的方法是用纯 C 函数实现的。C 函数可能会用代码来操作相关的数据结构,类之中的属性数 据就存放在那些数据结构里面。以 CoreData 为例,这些存取方法也许要和后端数据库通信, 以便获取或更新相应的值。

####备援接收者
当前接收者还有第二次机会能处理未知的选择子,在这一步中,运行期系统会问它:能 不能把这条消息转给其他接收者来处理。与该步骤对应的处理方法如下:

    - (id)forwardingTargetForSelector:(SEL)selector

方法参数代表未知的选择子,若当前接收者能找到备援对象,则将其返回,若找不到, 就返回 nil。通过此方案,我们可以用“组合”(composition)来模拟出“多重继承”(multiple inheritance)的某些特性。在一个对象内部,可能还有一系列其他对象,该对象可经由此方法 将能够处理某选择子的相关内部对象返回,这样的话,在外界看来,好像是该对象亲自处理 了这些消息似的。
请注意,我们无法操作经由这一步所转发的消息。若是想在发送给备援接收者之前先修 改消息内容,那就得通过完整的消息转发机制来做了

####完整的消息转发
如果转发算法已经来到这一步的话,那么唯一能做的就是启用完整的消息转发机制 了。首先创建 NSInvocation 对象,把与尚未处理的那条消息有关的全部细节都封于其中。 此对象包含选择子、目标(target)及参数。在触发 NSInvocation 对象时,“消息派发系统”(message-dispatch system)将亲自出马,把消息指派给目标对象。 此步骤会调用下列方法来转发消息:
    - (void)forwardInvocation:(NSInvocation*)invocation
这个方法可以实现得很简单:只需改变调用目标,使消息在新目标上得以调用即可。然 而这样实现出来的方法与“备援接收者”方案所实现的方法等效,所以很少有人采用这么简 单的实现方式。比较有用的实现方式为:在触发消息前,先以某种方式改变消息内容,比如 追加另外一个参数,或是改换选择子,等等。
实现此方法时,若发现某调用操作不应由本类处理,则需调用超类的同名方法。这样的话,继承体系中的每个类都有机会处理此调用请求,直至 NSObject。如果最后调用了 NSObject 类的方法,那么该方法还会继而调用“doesNotRecognizeSelector:”以抛出异常, 此异常表明选择子最终未能得到处理。

#### 消息转发全流程
这张流程图描述了消息转发机制处理消息的各个步骤。
![消息转发全程](/images/posts/MessageTrans.png)
接收者在每一步中均有机会处理消息。步骤越往后,处理消息的代价就越大。最好能在 第一步就处理完,这样的话,运行期系统就可以将此方法缓存起来了。如果这个类的实例稍 后还收到同名选择子,那么根本无须启动消息转发流程。若想在第三步里把消息转给备援的 接收者,那还不如把转发操作提前到第二步。因为第三步只是修改了调用目标,这项改动放 在第二步执行会更为简单,不然的话,还得创建并处理完整的 NSInvocation。
