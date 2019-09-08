#include<stdio.h>
#include<stdlib.h>

main(){
	
	int i = 3;
	int * p = &i;
	int ** q = &p;  // 2º∂÷∏’Î 
	int *** l = &q;
	printf("%d\n",*p);
	printf("%d\n",*(*q));
	printf("%d\n",*(*(*l)));
}
 
