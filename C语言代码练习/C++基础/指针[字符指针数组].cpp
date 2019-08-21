#include<iostream>
#include<string.h>
using namespace std;
void Print(const char*[],int);
int main(){
	const char* pn[]={"Fred","Barney","Wilma","Betty"};
	int num=sizeof(pn)/sizeof(char*);
	Print(pn,num);
	return 0;
} 

void Print(const char* arr[],int len){
	for(int i=0;i<len;i++)
		cout<<(int)arr[i]<<" "<<arr[i]<<endl;
}
