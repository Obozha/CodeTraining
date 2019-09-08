#include<stdio.h>
#include<string.h>

int main(){
	char str[] = "http://helloworld";
	int len = strlen(str),i;
	// Ö±½ÓÊä³ö×Ö·û´®
	printf("%s\n",str);
	
	for(i=0;i<len;i++){
		printf("%c",str[i]);
	} 
	printf("\n");
	return 0;
}
