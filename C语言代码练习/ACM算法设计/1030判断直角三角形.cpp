#include<stdio.h>

int main(){
	int a,b,c,temp;	
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){	// a��b�� ���ûb�� ����b�ŵ�һλ 
		temp=a;
		a=b;
		b=temp;
	}
	
	if(a>c){	// a��c�ȣ����ûc�� ����c�ŵ�һλ 
		temp=a;
		a=c;
		c=temp;
	}
	
	if(b>c){	// b��c�ȣ�ûc�� ��λ 
		temp=b;
		b=c;
		c=temp;
	}
	
	if(a*a+b*b==c*c){
		printf("yes");
	}else{
		printf("no");
	}
	return 0;
}
