#include<stdio.h>
#include<math.h>
#include<stdlib.h> 

int main(){
	int result=0;
	int m=0,n=0;
	int gcd1(int,int);
	printf("����������ֵ��");
	scanf("%d%d",&m,&n);
	
	result=gcd1(m,n);
	printf("%d��%d����ֵ���Լ����%d",m,n,result);
} 

int gcd1(int m,int n){
	m = abs(m);
	n = abs(n);
	while(m!=n){
		if(m>n)
			m=m-n;
		else
			n=n-m;
	}
	return m;
}
