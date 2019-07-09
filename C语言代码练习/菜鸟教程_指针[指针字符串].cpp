#include<stdio.h>
const int MAX=4;
int main(){
	const char *names[]={
		"Zara Ali",
		"Hina Ail",
		"Nuha Ail",
		"Sara Ail",
	};
	
	int i=0; 
	
	for(i=0;i<MAX;i++){
		printf("Value of names[%d]=%s\n",i,names[i]);
	}
	return 0; 
}

//指向字符的指针数组来存储一个字符串列表
