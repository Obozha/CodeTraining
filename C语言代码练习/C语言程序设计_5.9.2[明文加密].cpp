#include<stdio.h>

int main(){
	char c;
	c=getchar();					// ����һ���ַ����ַ�����c 
	while(c!='\n'){ 				// ���c��ֵ�Ƿ�Ϊ���з�'\n' 
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){ // c�������ĸ 
			if(c>='W'&&c<='Z'||c>'w'&&c<='z')
				c-=22;
			else
				c+=4;	 // �����26����ĸ����ĸ���ĸ֮һ��ʹc-22 �����ǰ��22����ĸ֮һ����ʹc��4������������ĸ���ĸ 
			printf("%c",c);
			c=getchar();
		}
	}
	printf("\n");
	return 0;
}
