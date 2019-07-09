#include<stdio.h>

int main(){
	int i,temp;
	int a[]={8,6,5,4,1};
	for(i=0;i<5/2;i++){
		temp=a[4-i];
		a[4-i]=a[i];
		a[i]=temp;

//	printf("%d %d  |",i,4-i);	²é¿´Î»ÖÃ		
	}	
		
	for(i=0;i<5;i++)
		printf("%d " ,a[i]);
} 
