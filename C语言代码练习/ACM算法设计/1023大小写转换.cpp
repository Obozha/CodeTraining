#include<stdio.h>

int main(){
	char c;
	scanf("%c",&c);
	if(c>=97&&c<=122){
		printf("%c",c-32);
	}else{
		printf("%c",c);
	}
	
}
