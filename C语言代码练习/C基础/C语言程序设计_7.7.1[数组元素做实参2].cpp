#include<stdio.h> 

int max(int x,int y); // �������� 
int main(){
	int a[10],m,n,i;
	printf("enter 10 integer numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\n");
	for(i=0,m=a[0],n=0;i<10;i++){
		if(max(m,a[i])>m) { // ��max�������ص�ֵ����m 
		 	
			m=max(m,a[i]); // max���ص�ֵȡ��m��ԭֵ 
			n=i;		   // �Ѵ���Ԫ�ص���ż����� ����n�С� 
		}
	}
	printf("The largest number is %d\n it is the %dth number. \n",m,n+1);
}

int max(int x,int y){ // ����max���� 
	return (x>y?x:y); // ����x��y�Ĵ��� 
}
