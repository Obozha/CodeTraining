#include<stdio.h>

int main(){
	char c;
	while((c=getchar())!='@'){
		if(c>='A'&&c<='Z')
			c+=32;
		if(c>='a'&&c<='y')
			c++;
		else if(c=='z')
			c='a';
		printf("%c",c);
	}
	return 0;
}
