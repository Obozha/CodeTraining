#include<stdio.h>

int main(){
	char c1;
	c1=getchar();
	if(c1>='a'&&c1<='z')
		printf("%d",c1-96);
	else if(c1>='A'&&c1<='Z')
		printf("%d",c1-64);
	return 0;
}
