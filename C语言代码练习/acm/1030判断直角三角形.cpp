#include<stdio.h>

int main(){
	int a,b,c,temp;	
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){	// a和b比 如果没b大 就让b放第一位 
		temp=a;
		a=b;
		b=temp;
	}
	
	if(a>c){	// a和c比，如果没c大 就让c放第一位 
		temp=a;
		a=c;
		c=temp;
	}
	
	if(b>c){	// b和c比，没c大 换位 
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
