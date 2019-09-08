#include<stdio.h>

int main(){
	char *name[]={"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
	char **p;
	int i;
	for(i=0;i<5;i++){
		printf("%s\n",*(name+i));
	}
	return 0;
}
