#include<stdio.h>
#include<time.h>

void getSeconds(unsigned long *par);

int main(){
	unsigned long sec;
	getSeconds(&sec);
	/* ���ʵ��ֵ */
	printf("Number of seconds:%ld\n",sec);
	return 0;
}

void getSeconds(unsigned long *par){
	/* ��ȡ��ǰ���� */
	*par=time(NULL);
	return;
}
