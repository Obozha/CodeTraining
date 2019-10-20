# Dev-Cpp_5.9.2 调试

* [Dev\-Cpp\_5\.9\.2 调试](#dev-cpp_592-%E8%B0%83%E8%AF%95)
  * [调试介绍](#%E8%B0%83%E8%AF%95%E4%BB%8B%E7%BB%8D)
  * [Debug面板介绍](#debug%E9%9D%A2%E6%9D%BF%E4%BB%8B%E7%BB%8D)
  * [使用举例](#%E4%BD%BF%E7%94%A8%E4%B8%BE%E4%BE%8B)
  * [总结](#%E6%80%BB%E7%BB%93)

## 调试介绍

就是使用工具给代码排除错误，这里我使用的版本是`Dev-Cpp_5.9.2`其他版本一样。

## Debug面板介绍

![dubug面板](dubug面板.png)

* Debug按钮：开始调试，快捷键`F5`
* Stop Execution：停止dubug程序
* Add watch：添加查看，一般是常量和变量，注意这里不能添加函数
* View CPU window：查看CPU对内存的执行过程
* Next line：执行下一行代码
* info function：进入当前执行的函数语句的源代码
* Skip function：跳过当前函数
* Continue：— 作用不大
* Next instruction：下一条语句（基本不用）
* Next instruction：进入当前语句（基本不用）

面板中常用的是`Next line`和`info function`，会用这两个所有的程序都可以调试了。

点击按钮和右边Send command to GDB是一回事，也可以直接在右边的编辑框选中之后修改命令按回车

## 使用举例

1. 首先设置断点
2. 按下F5
3. 通过Next line或者info function来执行语句，看自己需要，其间可以通过Add watch添加变量/常量查看。过程如下边的GIF。

![C++入门](GIF.gif)

> 注意1.不要选择函数语句添加查看变量，并且不要用鼠标选中函数，Dev会假死。  
> 注意2.如果未编译就执行的话，编译器会提示你的，如果你不进行编译就Debug，那么结果就是语句的位置很有可能就会错位，而且执行的结果不是你修改代码后的结果，编译器提示如下图。  
![dubug面板](编译后更新.png)

## 总结

DevC++只适合学习和一些竞赛写算法用，debug功能其实很弱，偶尔还会有一些bug，可以用debug解决一些常规问题，一些功能不必深入探究。
