#include<iostream>
using namespace std;

int sum1,sum2,sum3,sum4,sum5; 
int iArray[]={1,4,2,7,13,32,21,48,16,30};  //ȫ������
int*iPtr;
int main(){
	int size,n;
	size=sizeof(iArray)/sizeof(*iArray); // Ԫ�ظ���
	for(n=0;n<size;n++)
		sum1+=iArray[n];
	iPtr=iArray;
	for(n=0;n<size;n++)
		sum2+=iPtr[n];
	for(n=0;n<size;n++)
		sum3+=*(iArray+n);
	iPtr=iArray; // ��ʡ��	
	for(n=0;n<size;n++)
		sum4+=*iPtr++; // ���� *(iPtr++)
	iPtr=iArray; // ����ʡ�ԣ�
	for(n=0;n<size;n++)
		sum5+=*(iPtr+n);
//	for(n=0;n<size;n++)
//		sum6+=*iArray++; // iArray�ǳ��� 
	cout<<sum1<<endl<<sum2<<endl<<sum3<<endl<<sum4<<endl<<sum5<<endl; 
}
