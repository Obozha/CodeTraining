#include<stdio.h>

int main(){
	char c1;
	int letter=0,digit=0,other=0;
	while((c1=getchar())!='\n'){
		if(c1>='0'&&c1<='9')
			digit++;
		else if((c1>='A'&&c1<='Z')||(c1>='a'&&c1<='z'))
			letter++;
		else	
			other++;
	}
	printf("letter:%d\n",letter);
	printf("digit:%d\n",digit);
	printf("other:%d\n",other);
	return 0;
}
