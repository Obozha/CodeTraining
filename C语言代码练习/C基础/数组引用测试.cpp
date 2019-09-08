#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void setArray(int *arr){
	arr[0]=5;
}

int main(){
	int *arr =(int*)malloc(sizeof(int)*5);
	setArray(arr);
	cout<<arr[0];
}
