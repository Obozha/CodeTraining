#include<stdio.h>

int main (){
	int i,a[100],*p;
	p=a;
	
	for(i=0;i<100;i++){
		a[i]=i;
	}
	
	while(p<a+100){
		printf("%d ",*p++);
	}	
	
	
	// 因此在用 *p++形式的计算时
	// 一定要十分小心 *p++ 先取值再+1  *++p先+1再取值 
}
