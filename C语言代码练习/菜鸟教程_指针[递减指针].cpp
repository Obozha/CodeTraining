#include<stdio.h>

const int MAX = 3;

int main(){
	int var[] = {10,100,200};
	int i,*ptr;
	/*ָ�������һ��Ԫ�صĵ�ַ*/
	
	ptr = &var[MAX-1];
	for(i=MAX;i>0;i--){
		printf("�����ַ��var[%d]=%x\n",i-1,ptr);
		printf("����ֵ��var[%d]=%d\n",i-1,*ptr);
		/* �ƶ�����һ��λ�� */
		ptr--;
	}
}
