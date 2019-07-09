var tenInteger=new Array(); // 定义保存随机2位整数的数组

function createTenInteger(){ // 定义保存随机整数
	for(var i=0;i<10;i++){
		// 利用数学函数随机产生10~99之间的整数，并存入数组中
		tenInteger[i]=Math.floor(Math.random()*90+10);
	}
	postMessage(tenInteger.sort()); // 数组元素排序后传序给主线程
	setTimeout("createTenInteger()",1000); // 每隔1s重新产生1次
}
createTenInteger(); // 调用方法