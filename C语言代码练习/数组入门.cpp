#include<stdio.h>
#include<stdlib.h>

main(){
	
	printf("char������ռ���ڴ��С%d\n",sizeof(char));
	
	char arr[]= "Hello"; 
	int i[] = {1,2,3,4,5};
	
	printf("----------------------------------------\n");
	printf("����ַ�����\n");
	printf("arr[0]%c\n",arr[0]);
	printf("arr[1]%c\n",arr[1]);
	printf("arr[2]%c\n",arr[2]);
	printf("arr[3]%c\n",arr[3]);
	printf("arr[4]%c\n",arr[4]);
	printf("----------------------------------------\n");
	printf("����ַ��������ڴ��еĵ�ַ\n");
	printf("arr[0]%#x\n",&arr[0]);
	printf("arr[1]%#x\n",&arr[1]);
	printf("arr[2]%#x\n",&arr[2]);
	printf("arr[3]%#x\n",&arr[3]);
	printf("arr[4]%#x\n",&arr[4]);
	printf("arr%#x\n",&arr);
	// ÿ����һ���±꣬��ַ�������һ����λ
	// arr���Բ�ʹ��&����ȡ���ڴ��ַ��������ĵ�һ���±���ڴ��ַһ�� 
	printf("----------------------------------------\n");
	printf("��ָ������ַ�������ڴ��ַ\n");
	char * p = &arr[0];
	printf("arr[0]%c\n",*p);
	printf("arr[1]%c\n",*(p+1));
	printf("arr[2]%c\n",*(p+2));
	printf("arr[3]%c\n",*(p+3));
	printf("arr[4]%c\n",*(p+4));
	
	printf("----------------------------------------\n");
	printf("�����������\n");
	printf("i[0]%d\n",i[0]);
	printf("i[0]%d\n",i[1]);
	printf("i[0]%d\n",i[2]);
	printf("i[0]%d\n",i[3]);
	printf("i[0]%d\n",i[4]);
	printf("----------------------------------------\n");
	printf("��������������ڴ��еĵ�ַ\n");
	printf("i[0]%#x\n",&i[0]);
	printf("i[0]%#x\n",&i[1]);
	printf("i[0]%#x\n",&i[2]);
	printf("i[0]%#x\n",&i[3]);
	printf("i[0]%#x\n",&i[4]);
	// ��Ϊ��4���ֽ��������ڴ���ÿ���±꣬�ƶ�4��ֵ 
	printf("----------------------------------------\n");
	printf("��ָ����������������ڴ��еĵ�ַ\n");
	int * pi;
	pi = &i[0];
	printf("i[0]%d\n",*pi);
	printf("i[0]%d\n",*(pi+1));
	printf("i[0]%d\n",*(pi+2));
	printf("i[0]%d\n",*(pi+3));
	printf("i[0]%d\n",*(pi+4));
	// ��Ȼÿ���±���ڴ��ַ���4��ֵ������ָ��Ӽ��ǶԵ�λ�ļӼ����������������ڴ��ַ������Ӽ� 
	printf("----------------------------------------\n");
	printf("ָ��Ӽ�%d",(pi+2)-pi);
}
