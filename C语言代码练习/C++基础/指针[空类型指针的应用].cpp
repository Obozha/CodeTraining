#include<iostream>
#include<memory.h> 
using namespace std;

int main(){
	char src[10]="*********";
	char dest[10];
	char *pc=(char*)memcpy(dest,src,10);
	// 从src中拷贝n各字节到目标dest中 
	cout<<pc<<endl;
	return 0;
}
