#include<iostream>

using namespace std;
void Print(const char**);
int main(){
	const char*pn[]={"Fred","Barney","Wilma","Betty",NULL};
	Print(pn);
	return 0;
}

void Print(const char* arr[]){
	while(*arr!=NULL){
		cout<<(int)*arr<<" "<<*arr<<endl;
		arr++;
	}
}
