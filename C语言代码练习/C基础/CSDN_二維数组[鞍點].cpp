#include<stdio.h>

int main() {
	// ����һ�����֣�����������ξ����Ǽ��׵�
	int n;
	scanf("%d",&n);

	// ����n�׾����Լ���Ҫ�õ��ı���
	int matrix[n][n];
	int i,j,temp,count,flag=0;

	// ��������е�ÿһ����
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&temp);
			matrix[i][j]=temp;
		}
	}

	// ���Զ���������Ƿ���ȷ
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}

	// ��ʼѰ�Ұ���
	for(i=0; i<n; i++) {
		// �ҳ�ÿ���е���������
		temp=matrix[i][0]; // ��temp��count��ʶ��ÿ���������ֺ�λ��
		count=0;

		for(j=1; j<n; j++) {
			if(temp<matrix[i][j]) {
				temp=matrix[i][j];
				count=j;
			}
		}
		// ����һ�£������������֣��Ƿ��������е���С����
		for(j=0; j<n; j++) {
			if(matrix[j][count]<temp) {
				flag++;// ���������Сtemp,flag�Ͳ�Ϊ0
			}
		}

		if(flag==0) { // ����flagֵ�����Ϊ0��֤����������Ҫ�ҵİ���
			printf("%d %d\n",i,count);
			break;
		}
		flag=0;
	}

	if(i==n){
		printf("No");
	} 
	return 0;
}
