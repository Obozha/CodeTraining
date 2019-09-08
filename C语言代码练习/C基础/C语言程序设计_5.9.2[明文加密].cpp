#include<stdio.h>

int main(){
	char c;
	c=getchar();					// 输入一个字符给字符变量c 
	while(c!='\n'){ 				// 检查c的值是否为换行符'\n' 
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){ // c如果是字母 
			if(c>='W'&&c<='Z'||c>'w'&&c<='z')
				c-=22;
			else
				c+=4;	 // 如果是26个字母最后四个字母之一就使c-22 如果是前面22个字母之一，就使c加4，即变成其后第四个字母 
			printf("%c",c);
			c=getchar();
		}
	}
	printf("\n");
	return 0;
}
