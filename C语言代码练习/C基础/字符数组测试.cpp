#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string.h>
using namespace std;
int main(){
	char *c="helloworld";
//	c=(char*)malloc(sizeof(char)*6);
	cout<<sizeof(*c)<<" "<<sizeof(c)<<" "<<strlen(c);
}
