#include<iostream> 
#include<math.h>
using namespace std;

int main(){
	int a=3,b=5,c;
	
	// c=a*b + ++b; // 21
 	c=++ b + a*b; // 24
	// 先b+1 b是6 然后在计算6+(6*3)=24 
	
	// c=++ b *(a+b); // 求值使括号失去作用 
	
	cout<<c<<endl;
	return 0;
}


