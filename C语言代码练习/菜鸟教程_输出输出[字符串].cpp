#include<stdio.h>
#include<string.h>

int main() {
	char str[] = "HelloWorld";
	char *pstr;
	pstr = str;
	int len = strlen(str),i;

	for(i=0; i<len; i++) {
		printf("%c", *(pstr+i));
	}
	printf("\n");

	printf("%s\n",pstr);

	for(i=0; i<len; i++) {
		printf("%c", pstr[i]);
	}
	printf("\n");

	for(i=0; i<len; i++) {
		printf("%c",*(str+i));
	}
	printf("\n");


	int var = 20;
	int *ip;

	ip = &var;
	printf("Address of var variable: %p\n", &var  );

	/* ��ָ������д洢�ĵ�ַ */
	printf("Address stored in ip variable: %p\n", ip );

	/* ʹ��ָ�����ֵ */
	printf("Value of *ip variable: %d\n", *ip );

	return 0;
}


// ָ�������� ��ֵ ���ַ����Ĺ�ϵ 
