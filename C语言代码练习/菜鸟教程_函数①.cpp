#include<stdio.h>
int main(){
	int a,b,result;
	int max(int num1,int num2);
	// int max(int,int) �ں��������У����������Ʋ�����Ҫ 
	
	 
	printf("������������\n");
	scanf("%d,%d",&a,&b);
	result = max(a,b);
	printf("������������:%d",result);
	return 0;
	
} 

/* ���������������нϴ���Ǹ��� */
int max(int num1,int num2){
	/* �ֲ��������� */
	int result;
	
	if(num1 > num2)
		result = num1;
	else
		result = num2;
	
	return result;
}
