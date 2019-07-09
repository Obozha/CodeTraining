#include<stdio.h>
#include<stdlib.h>

main(){
	void function(int *mainp);
	int *mainp;
	printf("%#x\n",&mainp);
	function(mainp);
	
}

void function(int **mainp){
	int i = 5;
	*mainp = &i;
	printf("%#x\n",*mainp);
}
