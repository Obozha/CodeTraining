#include<stdio.h>
const int MAX = 3;
int main(){
	int var[] = {10,100,200};
	int i,*ptr;
	
	/* ָ���е������ַ */
	ptr = var;
	
	for(i=0;i<MAX;i++){
		printf("�����ַ��var[%d]=%x\n",i,ptr);
		printf("����ֵ��var[%d]=%d\n",i,*ptr);
		ptr++;
	}
	return 0;
}
