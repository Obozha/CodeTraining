#include<stdio.h>

int main(){
	int i,j,n=0;
	
	for(i=1;i<=4;i++)
		for(j=1;j<=5;j++,n++){ // n�����ۼ�������ݵĸ��� 
			if(n%5==0&&n!=0)			// ���������5�����ݺ��� 
				printf("\n");
			printf("%d\t",i*j);
		}
	return 0;
}
