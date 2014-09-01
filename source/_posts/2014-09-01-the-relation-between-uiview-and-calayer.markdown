---
layout: post
title: "Animation--UIView和CALayer的关系"
date: 2014-09-01 11:44:19 +0800
comments: true
categories: 
---

### 继承关系

1. UIView的继承结构为: **UIResponder : NSObject**。
官方的解释为:
> The **UIResponder** class defines an interface for objects that respond to and handle events. It is the superclass of UIApplication, UIView and its subclasses (which include UIWindow). Instances of these classes are sometimes referred to as responder objects or, simply, responders.

    >The **UIView** class defines a rectangular area on the screen and the interfaces for managing the content in that area. At runtime, a view object handles the rendering of any content in its area and also handles any interactions with that content. The UIView class itself provides basic behavior for filling its rectangular area with a background color. More sophisticated content can be presented by subclassing UIView and implementing the necessary drawing and event-handling code yourself. The UIKit framework also includes a set of standard subclasses that range from simple buttons to complex tables and can be used as-is. For example, a UILabel object draws a text string and a UIImageView object draws an image.
    
    由官方的解释可以看出，UIResponder是用来相应事件的，相应的UIView可以响应用户事件。
    
2. CALayer的继承结构为：CALayer的继承结构为：**CALayer: NSObject**。
CALayer是直接继承NSObject的，因为缺少了UIResponder类，所以CALayer是不能响应用户事件的。
>The CALayer class is the model class for layer-tree objects. It encapsulates the position, size, and transform of a layer, which defines its coordinate system. It also encapsulates the duration and pacing of a layer and its animations by adopting the CAMediaTiming protocol, which defines a layer’s time space.

    从官方的解释中可以看出，CALayer定义了position、size、transform、animations 等基本属性.

从上面的分析中，我们可以得出UIView主要负责事件的响应处理，CALayer主要负责绘制。那么UiView中的size、Frame、Position又是怎么来的呢？

###所属框架
1. **UIView**是在 /System/Library/Frameworks/UIKit.framework中定义的。
>The UIKit framework provides the classes needed to construct and manage an application’s user interface for iOS. It provides an application object, event handling, drawing model, windows, views, and controls specifically designed for a touch screen interface.

    可见UIKit主要是用来构建用户界面，并且是可以响应事件的（得意于UIView的父类UIResponder）。那么UIView是通过什么来绘制图片和文字信息的呢？而iOS中2D图像绘制是通过QuartzCore.framework实现的。难道是通过QuartzCore.framework实现的？那又是通过什么方式和QuartzCore.framework联系起来的呢？
    
2. **CALayer**是在/System/Library/Frameworks/QuartzCore.framework定义的。而且CALayer作为一个低级的，可以承载绘制内容的底层对象出现在该框架中。

    UIView相比CALayer最大区别是UIView可以响应用户事件，而CALayer不可以。UIView侧重于对显示内容的管理，CALayer侧重于对内容的绘制。
>Core Animation doesn't provide a means for actually displaying layers in a window, they must be hosted by a view. When paired with a view, the view must provide event-handling for the underlying layers, while the layers provide display of the content.
The view system in iOS is built directly on top of Core Animation layers. Every instance of UIView automatically creates an instance of a CALayer class and sets it as the value of the view’s layer property. You can add sublayers to the view’s layer as needed.

**由此可见UIView是基于CALayer的高层封装。The view system in iOS is build directly on top of Core Animation layers**


### Summary

- UIView是iOS系统中界面元素的基础，通过CALyaer来绘制内容并显示，并且可以处理用户事件。而CALayer只关心绘制，对内同进行动画处理，不能处理用户事件。
- UIView和CALayer是相互依赖的关系。UIView依赖与calayer提供的内容，CALayer依赖uivew提供的容器来显示绘制的内容。归根到底CALayer是这一切的基础，如果没有CALayer，UIView自身也不会存在，UIView是一个特殊的CALayer实现，添加了响应事件的能力。
- UIView的Layer树形在系统内部，被系统维护着三份Copy。
    第一份，**模型树(Model Layer Tree)**  就是代码可以操纵的，例如更改Layer的属性等等就在这一份
    第二份，**呈现树(Presentation layer Tree)**  这是一个中间层，呈现树的属性和动画运行过程中界面看到的是一致的，也可以说这层是Layer在屏幕中的真实位置。
    第三份，**渲染树(Rendering Layer Tree)**  渲染树是私有的，开发者无法访问到。渲染树是对呈现树的数据进行渲染,为了不阻塞主线程,渲染的过程是在单独的进程或线程中进行的,所以你会发现Animation的动画并不会阻塞主线程.
    这三棵树的逻辑结构是一样的，区别只有各自的属性。
- CoreAnimation负责维护两个平行layer层次结构：model layer tree(模型层树)和presentation layer tree (表示层树)。前者反映我们直接能看到的layers的状态，而后者的layers则是动画正在表现的近似值