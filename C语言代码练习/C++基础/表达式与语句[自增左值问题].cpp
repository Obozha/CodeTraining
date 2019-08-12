#include<iostream> 
#include<math.h>
using namespace std;

int main(){
 	int a=5;
	++(++a); 
	// ++(a++); 
	cout<<a<<endl;
	
	// 增量左值问题 
	
	// 由于 前增量 操作返回的值即 修改之后的变量值，所以返回的仍然是一个左值
	// 由于 后增量 操作返回的值是 原先a的值，而后a的值已经发生变化，故返回的不能是当前a，
	// 只能是过去的a值，不能是左值。 
	return 0;
}


