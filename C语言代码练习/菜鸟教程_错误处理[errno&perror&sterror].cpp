#include<stdio.h>
#include<errno.h>
#include<string.h>

extern int errno;

// ��Ӧ��ʹ�� stderr �ļ�����������еĴ��� 
int main(){
	FILE *pf;
	int errnum;
	pf = fopen("unexit.txt","rb");
	if(pf == NULL){
		errnum = errno;
		fprintf(stderr,"�����:%d\n",errno);
		perror("ͨ��perror�������");
		fprintf(stderr,"���ļ�����:%s\n",strerror(errnum)); 
	}else{
		fclose(pf);
	}
	return 0;
} 

// c�����ṩ��perror()��strerror()��������ʾ��errno��ص��ı���Ϣ

// perror()������ʾ�����������ַ��� ���һ��ð�š�һ���ո�͵�ǰerrnoֵ���ı��ı�ʾ��ʽ��
// strerror() ����������һ��ָ�룬ָ��ָ��ǰerrnoֵ���ı���ʾ��ʽ 
