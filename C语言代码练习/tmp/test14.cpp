#include<iostream>
#include<stdio.h>
#include<string.h> 
using namespace std;

int main(){
	char a[20]="HelloWorld";
	
	cout<<strlen(a)<<endl;
	
	const char *str;
	str="Hello";
	printf("%p ",str);
	
	str="HelloWor";
	printf("%p ",str);

	str="ThisisFuckingdoing"; 
	printf("%p ",str);

//	cout<<str;
	
	printf("\n%p ",a);

	strcpy(a,"ThisisFuckingdoing");
	printf("%p ",a);

	strcpy(a,"HelloWor");
	printf("%p ",a);
	 
}
