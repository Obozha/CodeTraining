#include<stdio.h>

int main(){
	int m,n; // ����m��n���洢ͷ�ĸ����ͽŵ�ֻ�� 
	int x,y; // ����x��y���ֱ𴢴漦�����ӵ����� 
	scanf("%d %d",&m,&n);
	y=(n-2*m)/2; // �ⷽ�̼�������ӵĸ���y
	x=m-y; // ��������ĸ���x
	printf("%d %d\n",x,y);
	return 0; 
}
