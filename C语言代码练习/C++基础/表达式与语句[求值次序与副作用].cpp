#include<iostream> 
#include<math.h>
using namespace std;

int main(){
	int a=3,b=5,c;
	
	// c=a*b + ++b; // 21
 	c=++ b + a*b; // 24
	// ��b+1 b��6 Ȼ���ڼ���6+(6*3)=24 
	
	// c=++ b *(a+b); // ��ֵʹ����ʧȥ���� 
	
	cout<<c<<endl;
	return 0;
}


