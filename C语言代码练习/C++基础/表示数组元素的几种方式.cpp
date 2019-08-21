#include<iostream>
using namespace std;

int sum1,sum2,sum3,sum4,sum5; 
int iArray[]={1,4,2,7,13,32,21,48,16,30};  //全局数组
int*iPtr;
int main(){
	int size,n;
	size=sizeof(iArray)/sizeof(*iArray); // 元素个数
	for(n=0;n<size;n++)
		sum1+=iArray[n];
	iPtr=iArray;
	for(n=0;n<size;n++)
		sum2+=iPtr[n];
	for(n=0;n<size;n++)
		sum3+=*(iArray+n);
	iPtr=iArray; // 可省略	
	for(n=0;n<size;n++)
		sum4+=*iPtr++; // 等于 *(iPtr++)
	iPtr=iArray; // 不可省略！
	for(n=0;n<size;n++)
		sum5+=*(iPtr+n);
//	for(n=0;n<size;n++)
//		sum6+=*iArray++; // iArray是常量 
	cout<<sum1<<endl<<sum2<<endl<<sum3<<endl<<sum4<<endl<<sum5<<endl; 
}
