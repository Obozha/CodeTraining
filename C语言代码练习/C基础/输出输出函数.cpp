#include<stdio.h>
#include<stdlib.h>
/**
%d int 
%ld long int
%hd short int
%c char
%f float
%lf double
%u �޷���
%x ʮ���������int����long int����short int
%o �˽������
%s �ַ��� 
**/
main(){
	int i = -3;
	long int li = 111;
	short int si = 111;
	char c = 'a';
	float f = 3.14;
	double d = 3.14;
	char s[] = "Hello World!";
	
	printf("%d\n",i);
	printf("%ld\n",li);
	printf("%hd\n",si);
	printf("%c\n",c);
	printf("%f\n",f);
	printf("%lf\n",d);
	printf("%u\n",i);
	printf("%#x\n",li); // #���0x 
	printf("%#o\n",li);   // #��ӵ�0 
	printf("%s\n",s);
	
	system("pause");
	return 0;
}

