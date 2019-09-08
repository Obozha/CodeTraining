#include<stdio.h>

int main(){
	char c;
	int count=0;
	while((c=getchar())!='\n'){
		if(c>='0'&&c<='9')
			count++;
	}
	printf("%d",count);
	return 0;
}
