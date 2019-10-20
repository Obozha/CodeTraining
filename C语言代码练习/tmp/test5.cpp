#include<iostream>
#include<stdio.h>
using namespace std;

int  main() {
	char str1[] = "abc";
	char str2[] = "abc";
	const char str3[] = "abc";
	const char str4[] = "abc";
	const char *str5 = "abc";
	const char *str6 = "abc";
	char *str7 = "abc";
	char *str8 = "abc";
	cout << (str1 == str2) << endl;
	cout << (str3 == str4) << endl;
	cout << (str5 == str6) << endl;
	cout << (str7 == str8) << endl;
	
	printf("%p %p\n",str7,str8);
	printf("%p %p\n",str5,str6);
	printf("%p %p\n",str3,str4);
	
}
