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
	
	
	// ������� *p++��ʽ�ļ���ʱ
	// һ��Ҫʮ��С�� *p++ ��ȡֵ��+1  *++p��+1��ȡֵ 
}
