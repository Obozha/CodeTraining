#include<stdio.h>

int main(){
	int *p1,*p2,*p,a,b;								//p1,p2��������int*���� 
	printf("please enter two integer numbers:");	
	scanf("%d,%d",&a,&b);					 		//������������ 
	p1=&a;											//ʹp1ָ�����a 
	p2=&b;											//ʹp2ָ�����b 
	if(a<b){										//���a<b 
		p=p1;										//ʹp1��p2���� 
		p1=p2;
		p2=p;
	}
	printf("a=%d,b=%d\n",a,b);						//���a,b 
	printf("max=%d,min=%d\n",*p1,*p2);				//���p1��p2��ָ��ı�����ֵ 
	return 0;
} 
