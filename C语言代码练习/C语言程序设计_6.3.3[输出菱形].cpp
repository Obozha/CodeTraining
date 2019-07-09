#include<stdio.h>

int main(){
	printf("\0");
	char diamond[][5]={
		{' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},{' ','*',' ','*'},{' ',' ','*'}
	}; 
	
	int k;
	char c[]="hello";
	c[2]='\0';
	for(k=0;k<5;k++){
		printf("%c",c[k]);
//		printf("%d",k);
	}
	
	
	
//	int i,j;
//	for(i=0;i<5;i++){
//		for(j=0;j<5;j++)
//			printf("%c",diamond[i][j]);
//		printf("\n");
//	}
	
} 
