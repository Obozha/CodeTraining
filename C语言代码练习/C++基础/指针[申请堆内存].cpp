#include <iostream>
using namespace std;
int main( ) {
	int arraysize; // Ԫ�ظ���
	int *array,*ip;
	cout<<"please input a number of array"<<endl;
	cin>>arraysize;
	if((array=new int[arraysize])==NULL){
		cout<<"can't allocate more memory,terminating.\n";
		return 0;
	} 
	for(int count=0;count<arraysize;count++){
		array[count]=count*2; // ������Ԫ�ظ�ֵ 
	}
	for(int count=0;count<arraysize;count++)
		cout<<array[count]<<" "; // �������Ԫ��
	cout<<endl;
	ip=new int;
	*ip=8;
	cout<<*ip<<endl;
	delete []array;
	delete ip; // �ͷŶ��ڴ�
	return 0; 
}

