#include<stdio.h>    	
#include<stdlib.h>

main(){
	
	short i1 = 2;
	int i = 1;
	long i3 = 4;
	float f = 1.0;
	double d = 1.0;
	char a ='a';
	bool b = true;
		
	long long ll =123213432;
	
	printf("i��ֵΪ%d\n",i);
	printf("i1��ֵΪ%d\n",i1);
	printf("d��ֵΪ%f\n",d);
	printf("a��ֵ��%c\n",a);
	printf("f��ֵ��%f\n",f);
	printf("b��ֵ��%b\n",b);
	
	printf("shortֵ��ռλ��С%d\n",sizeof(short));
	printf("intֵ��ռλ��С%d\n",sizeof(int));
	printf("longֵ��ռλ��С%d\n",sizeof(long));
	printf("floatֵ��ռλ��С%d\n",sizeof(float));
	printf("doubleֵ��ռλ��С%d\n",sizeof(double));
	printf("boolֵ��ռλ��С%d\n",sizeof(bool));
	printf("charֵ��ռλ��С%d\n",sizeof(char));
	
	printf("long longֵ��ռλ��С%d\n",sizeof(long long));
	printf("short intֵ��ռλ��С%d\n",sizeof(short int));
	printf("long intֵ��ռλ��С%d\n",sizeof(long int));
	
	system("pause");
	return 0;
}
