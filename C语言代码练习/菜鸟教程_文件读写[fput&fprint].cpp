#include<stdio.h>

int main(){
	int test1,test2;
	
	FILE *fp = NULL;
	fp = fopen("G:/code/tmp/test.txt","w+");
	test1 = fprintf(fp,"This is testing for fprint...\n");
	printf("%d",test1);
	
	test2 = fputs("This is testing for fputs...\n",fp);
	// ����fputs()���ַ���sд�뵽fp��ָ���������С����д��ɹ������᷵��һ���Ǹ�ֵ
	// ����������� ��᷵��EOF  
	
	printf("%d",test2);
		

	fclose(fp);
	
}
