#include<stdio.h>
int main(){
	/* �ֲ��������� */
	void swap(int*,int*); 
	int a=100,b=200;
	printf("����ǰ��a��ֵ:%d\n",a);
	printf("����ǰ��b��ֵ:%d\n",b);
	
	swap(&a,&b);
	
	/* ���ú���������ֵ 
	*  &a��ʾָ��a��ָ�룬������a�ĵ�ַ 
	*  &b��ʾָ��b��ָ�룬������b�ĵ�ַ 
	*/
	
	printf("������a��ֵ:%d\n",a);
	printf("������b��ֵ:%d\n",b);
	
	return 0;
}

void swap(int *x,int *y){
	int temp;
	temp = *x; /* ������ַx��ֵ */
	*x = *y; /* ��y*��ֵ��x* */
	*y = temp; /* ��temp��ֵ��y* */
	return;
}
