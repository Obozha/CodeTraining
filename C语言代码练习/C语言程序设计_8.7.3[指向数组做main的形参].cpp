#include<stdio.h>

// argc ��argument count����д��������main�����Ĳ����ĸ�����
// argv ��argment vector����д��������main�����Ĳ������л�ָ�� 

/**
 argument  n. ��֤���۾ݣ�������������Ҫ
 vector n. ʸ���������ߣ����� vt. �����ߵ絼��
*/ 
 
int main(int argc,char * argv[]){
	while(argc-->1){
		printf("%s\n",*++argv);
	}

	// argc-->1 ָ����argc����1�ȴ�С Ȼ����-1 
	// ++argv �����ȼ�1 ��ȡֵ 
} 
