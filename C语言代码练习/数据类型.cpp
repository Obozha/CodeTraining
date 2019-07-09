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
	
	printf("i的值为%d\n",i);
	printf("i1的值为%d\n",i1);
	printf("d的值为%f\n",d);
	printf("a的值是%c\n",a);
	printf("f的值是%f\n",f);
	printf("b的值是%b\n",b);
	
	printf("short值的占位大小%d\n",sizeof(short));
	printf("int值的占位大小%d\n",sizeof(int));
	printf("long值的占位大小%d\n",sizeof(long));
	printf("float值的占位大小%d\n",sizeof(float));
	printf("double值的占位大小%d\n",sizeof(double));
	printf("bool值的占位大小%d\n",sizeof(bool));
	printf("char值的占位大小%d\n",sizeof(char));
	
	printf("long long值的占位大小%d\n",sizeof(long long));
	printf("short int值的占位大小%d\n",sizeof(short int));
	printf("long int值的占位大小%d\n",sizeof(long int));
	
	system("pause");
	return 0;
}
