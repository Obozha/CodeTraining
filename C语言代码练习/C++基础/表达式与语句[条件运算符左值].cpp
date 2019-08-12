#include<iostream> 
#include<math.h>
using namespace std;

int main(){
	// 在一个条件运算符的表达式中，如果后边两个表达式值类型相同，均为左值
	// 则该条件运算符表达式的值为左值表达式 
	int x=5;
	long a,b;
	(x?a:b)=1; // ok 因为左右都是左值
	//(x?x:a)=2; // error x和a不是一个类型。 编译器将其理解为(long)x和a 
	//(x==a?1:a)=3; // error:1不能是左值 
	cout<<a;
}
