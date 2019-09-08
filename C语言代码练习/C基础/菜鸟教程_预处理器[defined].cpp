#include<stdio.h>

#if !defined(MESSAGE)
	#define MESSAGE "You wish"
#endif

int main(){
	printf("Here is the meessage:%s\n",MESSAGE);
	return 0;
}
