#include<stdio.h>

int main(){
	FILE *fp = NULL;
	char buff[255];
	
	fp = fopen("tmp/test.txt","r+");
	fscanf(fp,"%s",buff);
	printf("1:%s\n",buff);
	
	fgets(buff,255,fp);
	// fgetc(); ������fp��ָ��������ļ��ж�ȡһ���ַ� ����ֵ�Ƕ�ȡ���ַ�
	// ����������󷵻�EOF��
	
	// fgets(); ������fp��ָ����������ж�ȡn-1���ַ�������Ѷ�ȡ���ַ������Ƶ�
	// ������buf,�������׷��һ��null�ַ�����ֹ�ַ��� 
	
	
	printf("2:%s\n",buff);
	// buffָ������ ָ������ 
	
	
	fgets(buff,255,fp);
	printf("3:%s\n",buff);
	fclose(fp);
} 
