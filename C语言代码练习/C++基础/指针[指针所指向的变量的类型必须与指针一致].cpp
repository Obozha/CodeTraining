#include <iostream>
using namespace std;
int main( ) {
	float f=34.5;
	float* fPtr=&f; //����ָ��
	int* iPtr=&f; //warning:����������ĵ�ַ��������ָ��
	iPtr=fPtr; //warning:������ָ�븳������ָ��
	cout<<f<<endl;
	cout<<"iPtr:"<<iPtr<<"=>"<<*iPtr<<endl;
	cout<<"fPtr:"<<fPtr<<"=>"<<*fPtr
	    <<endl<<endl;
	*iPtr=*fPtr; //��ʽ����ת��
	cout<<f<<endl;
	cout<<*iPtr<<endl;
	cout<<*fPtr<<endl;
	return 0;
}

