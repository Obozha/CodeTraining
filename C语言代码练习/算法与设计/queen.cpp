#include<stdio.h>
#include<stdlib.h>
#
#define N 20
int q[N];
int count=0;

void dispasolution(int n){
	printf("   ��%d����  ",++count);
	for(int i=1;i<=n;i++){
		printf("(%d,%d)",i,q[i]);
	}
	printf("\n");
} 

bool place(int i,int j){
	if(i==1)
		return true;
	int k=1;
	while(k<i){
		if(q[k]==j||abs(q[k]-j)==abs(i-k))
			return false;
		k++;
	}
	return true;
}

// 1.���öϵ�
// 2.��Debug�� ---> ע�� ��������޸�֮�� ��Ҫ���±�����Debug 
// 3.Next line ���� into function �ڼ����ѡ�б�����Ӳ鿴 Add watch 

// Next line һ��һ������
// info function ���뺯������ڲ���Դ���� 

void queen(int i,int n){
	if(i>n){
		dispasolution(n);
	}else{
		for(int j=1;j<=n;j++){
			if(place(i,j)){
				q[i]=j;
				queen(i+1,n);
			}
		}
	}
}

int main(){
	int n;
	printf("�ʺ�����(n<20)n=");
	scanf("%d",&n);
	if(n>20)
		printf("nֵ̫�������");
	else{
		printf("%d�ʺ�����������£�\n",n);
		queen(1,n); // ����1~n���ʺ� 
	}

}
