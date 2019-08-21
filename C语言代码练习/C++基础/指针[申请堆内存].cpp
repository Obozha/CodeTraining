#include <iostream>
using namespace std;
int main( ) {
	int arraysize; // 元素个数
	int *array,*ip;
	cout<<"please input a number of array"<<endl;
	cin>>arraysize;
	if((array=new int[arraysize])==NULL){
		cout<<"can't allocate more memory,terminating.\n";
		return 0;
	} 
	for(int count=0;count<arraysize;count++){
		array[count]=count*2; // 给数组元素赋值 
	}
	for(int count=0;count<arraysize;count++)
		cout<<array[count]<<" "; // 输出数组元素
	cout<<endl;
	ip=new int;
	*ip=8;
	cout<<*ip<<endl;
	delete []array;
	delete ip; // 释放堆内存
	return 0; 
}

