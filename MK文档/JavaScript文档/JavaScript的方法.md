### 方法

***

在一个对象中绑定函数，称为这个对象的方法。
在JavaScript中，对象的定义是这样的：

	var xiaoming = {
    	name:'小明',
        birth:1990
    };

但是，如果给xiaoming绑定一个函数，就可以做更多的事情，比如，写个age()方法，返回xiaoming的年龄:

	var xiaoming{
    	name:'小明',
    	birth:1990,
        age:function(){
        	var y = new Date().getFullYear();
            return y - this.birth;
        }
    }

xiaoming.age; // function xiaoming.age()
xiaoming.age(); // 今年调用是25，明年调用就变成26

绑定到对象上的函数称为方法，和普通函数也没啥区别，但是它在内部使用了一个`this`关键字，这个东东是什么？

在一个方法内部，`this`是一个特殊变量，它始终指向当前对象，也就是`xiaoming`这个变量。所以，`this.birth`可以拿到`xiaoming`的`birth`属性

让我们拆开写：

	function getAge(){
    	var y = new Date().getFullYear();
        return y - this.birth;
    }

	var xiaoming = {
    	name:'小明',
        birth:1990,
        age:getAge
    };

单独调用函数`getAge()`怎么返回了`NaN`?
JavaScript的函数内部如果调用了`this`,那么这个`this`到底指向谁？

答案是，视情况而定!

如果以对象的方法形式调用，比如 `xiaoming.age()`,该函数的`this`指向被调用的对象，这是复合我们预期的。

如果单独调用函数，比如`getAge()`，此时，该函数的`this`指向全局对象，也就是`window`。

这么写也不行

	var fn = xiaoming.age; // 先拿到xiaoming的age()函数
    fn();

要保证`this`指向正确，必须用obj.xxx();的形式调用！

由于这是一个巨大的设计错误，要想纠正可没那么简单，ECMA决定，在strict模式下让函数`this`指向`undefined`，因此，在strict模式下，你会得到一个错误：

	`use strict`;

    var xiaoming = {
    	name :'小明',
        birth: 1990,
        age:function(){
        	var y = new Date().getFullYear();
            return y - this.birth;
        }
    }

	var fn = xiaoming.age;
    fn(); // Uncaught TypeError:Cannot read property 'birth' of undefined

这个决定只是让错误及时暴露出来，并没有解决`this`应该指向的正确位置

有些时候，喜欢重构的你把方法重构了一下

	'use strict'

	var xiaoming = {
    	name:'小明',
        birth:1990,
        age:function(){
        	function getAgeFromBirth(){
            	var y = new Date().getFullYear();
                return y - this.birth;
            }
            return getAgeFromBirth();
        }
    }

	xiaoming.age(); // Uncaught TypeError:Cannot read property 'birth' of undefined

结果又报错了！原因是`this`指针只在`age`方法的函数内指向`xiaoming`，在函数内部定义的函数，`this`又指向`undefined`了！(在非strict模式下，它重新指向全局对象`window`!)

修复的方法也不是没有，我们用一个`that`变量首先捕获`this`:

	'use strict'

	var xiaoming{
    	name:'小明',
        birth:1990,
        age:function(){
        	var that = this; // 在方法内部以开始就捕获this
            function getAgeFromBirth(){
            	var y = new Date().getFullYear();
                return y - that.birth; // 用that而不是this;
            }
            return getAgeFromBirth();
        }
    };
    xiaoming.age();

用`var that = this;`你就可以放心地在方法定义其他函数，而不是把所有语句都堆到一个方法中。

####apply

虽然在一个独立的函数调用中，根据是否是strict模式，`this`指向`undefined`或`window`，不过，我们还是可以控制`this`的指向的！

要指定函数的`this`指向哪个对象，可以用函数本身的`apply`方法，它接收两个参数，第一个参数就是需要绑定的`this`变量，第二个参数是`Array`，表示函数本身的函数

用`apply`修复`getAge()`调用：

	function getAge(){
    	var y = new Date().getFullYear();
        return y - this.birth;
    }

	var xiaoming = {
    	name:'小明',
        birth:1990,
        age:getAge
    };

	xiaoming.age(); // 25
	getAge.apply(xiaoming,[]); // 25 this指向xiaoming 参数为空

另一个与`apply`类似的方法是call();唯一区别是：
* apply()把参数打包成`Array`再传入;
* call ()把参数按顺序传入

比如调用`Math.max(3,4,5)`，分别用`apply()`和`call()`实现如下：

	Math.max.apply(null,[3,4,5]); // 5
    Math.max.call(null,3,4,5); // 5

对普通的函数调用，我们同常把`this`绑定为`null`.

####装饰器

利用`apply()`，我们还可以动态改变函数的行为。

JavaScript的所有的对象都是动态，即使内置的函数，我们也可以中心指向新的函数。

现在假定我们像统计一下代码一共调用了多少次`parseInt()`，可以把所有的调用都找出来，然后手动加上`count += 1`，不过这样太傻了，最佳方案是用我们自己的函数替换默认的`parseInt()`:

	var count = 0;
    var oldParseInt = parseInt; // 保留原函数

	window.parseInt = function(){
    	count += 1;
        return oldParseInt.apply(null,arguments); // 调用原函数
    }；
    // 测试：
    parseInt('10');
	parseInt('20');
	parseInt('30');
    count; // 3

























