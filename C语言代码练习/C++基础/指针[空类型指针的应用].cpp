#include<iostream>
#include<memory.h> 
using namespace std;

int main(){
	char src[10]="*********";
	char dest[10];
	char *pc=(char*)memcpy(dest,src,10);
	// ��src�п���n���ֽڵ�Ŀ��dest�� 
	cout<<pc<<endl;
	return 0;
}
