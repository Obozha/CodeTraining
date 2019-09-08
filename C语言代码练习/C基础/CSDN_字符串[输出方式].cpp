#include<stdio.h>
#include<string.h> 

int main(){
	char str[] = "http://helloworld";
	char *pstr = str;
	
	int len  = strlen(str),i;
	
	// 使用*(pstr+i)
	for(i=0;i<len;i++){
		printf("%c",*(pstr+i));	
	}
	printf("\n");
	
	// 使用pstr[i]
	for(i=0;i<len;i++){
		printf("%c",pstr[i]);	
	} 
	printf("\n");
	
	// 使用*(str+i)
	for(i=0;i<len;i++){
		printf("%c",*(str+i));
	}
	printf("\n");
	
	printf("%s",str);
	printf("%p",&str);
	
	return 0;
	
}
