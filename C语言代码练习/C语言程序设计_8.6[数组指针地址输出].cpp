#include<stdio.h>


// ���ַ��������������� ��ָ�����ֱ��ָ��Ԫ�� ����ÿ�ζ����¼����ַ
// ��p++�������ԼӲ����ǱȽϿ�ġ������й��ɵظı��ַ (p++)�ܴ�����ִ��Ч�� 
 
int main(){
	int a[10];
	int *p,i;
	printf("Please enter 10 integer numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]); 
	for(p=a;p<(a+10);p++)
		//printf("%d ",*p);
		printf("%d ",p);
	printf("\n");


	return 0;	
	


}


