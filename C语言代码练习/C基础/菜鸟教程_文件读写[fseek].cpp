#include<stdio.h>

int main(){
//	FILE *fp = NULL;
//	fp = fopen("tmp/test.txt","r+");
//	fprintf(fp,"This is testing for fprintf...\n");
//	fseek(fp,5,SEEK_SET);
//	if(fputc(65,fp)==EOF){
//		printf("fputc fail");
//	} 
//	fclose(fp);

	printf("%c",65);
	
	FILE *fp;
	fp = fopen("tmp/file.txt","w+");
	fputs("This is runoob.com",fp);
	
	fseek(fp,7,SEEK_SET);
	fputs("C programming Langauge",fp);
	fclose(fp); 
	
	return 0;
} 

// SEEK_SET 0 �ļ�ͷ 
// SEEK_CUR 1 ��ǰ�� 
// SEEK_END 2 �ļ�β����ƫ����offset 

// ָ��ͷ��Ҫָ�����ٸ��ֽڣ�ֻҪ����ƫ������
// fseek(fp,1,SEEK_CUR); ��Ե�ǰλ�������ƶ�һ���ֽ�
// fseek(fp,-1,SEEK_CUR); ��Ե�ǰλ����ǰ�ƶ�һ���ֽ� 
