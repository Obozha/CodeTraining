### map/reduce

如果你读过Google的那篇大名鼎鼎的论文 "MapReduce:Simplified Data Processing on Large Clusters"  你就能大概明白map/reduce的概念。

#### map

举例说明，比如有一个函数f(x)=x^2^,要把这个函数作用在一个数组`[1,2,3,4,5,6,7,8,9]`上，就可以用`map`实现

由于`map()`方法定义在JavaScript的`Array`中，我们调用`Array`的`map()`方法，传入我们自己的函数，就得到了一个新的`Array`作为结果:

	function pow(x){
    	return x * x;
    }
    var arr = [1,2,3,4,5,6,7,8,9];
    arr.map(pow); // [1,4,9,16,25,36,49,64,81]

`map()`传入的参数是`pow`,即函数对象本身。

你可能会想，不需要`map()`，写一个循环，也可以计算出结果:

	var f = function(x){
    	return x * x;
    };

	var arr = [1,2,3,4,5,6,7,8,9];
    var result = [];
    for(var i = 0; i < arr.length; i++){
    	result.push(f(arr[i]));
    }

的确可以，但是，从上面的循环代码，我们无法一眼看明白 "把f(x)作用在Array的每一个元素并把结果生成一个新的Array"。

所以，map()作为高阶函数，事实上它把运算规则抽象了，因此，我们不但可以计算简单的f(x) = x^2^,还可以计算任意复杂的函数，比如，把`Array`的所有数字转为字符串:

	var arr = [1,2,3,4,5,6,7,8,9];
	arr.map(String); // ['1','2','3','4','5','6','7','8','9'];

只需要一行代码。

#### reduce

再看reduce的用法，Array的reduce()把一个函数作用在这个Array的`[x1,x2,x3...]`上，这个函数必须接收两个函数，`reduce()`把结果继续和序列的下一个元素做累积计算，其效果就是:

	[x1,x2,x3,x4].reduce(f) = f(f(f(x1,x2),x3),x4)

比方说对一个`Array`求和，就可以用`reduce`实现：
	var arr = [1,3,5,7,9];
    arr.reduce(function(x,y){
    	return x + y;
    });









