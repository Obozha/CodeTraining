#include<stdio.h>


int main(){
	int m,i,n;
	int a[10];
	int max(int,int);
	
	printf("enter 10 integer numbers:");   
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	printf("\n");
	for(i=0,m=a[0],n=0;i<10;i++){
		if(max(a[i],m)>m){
			m=max(a[i],m);
			n=i;
		}
	}
	printf("The largest number is %d \nit is the %dth number.\n",m,n+1);
} 

int max(int x,int y){
	return (x>y?x:y);
} 

 
