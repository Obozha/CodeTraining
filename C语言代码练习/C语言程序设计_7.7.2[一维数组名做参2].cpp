#include<stdio.h>

float getAvg(float array[10]);
int getLength(float a[]);


int main(){
	float score[10],aver;
	int i;
	
	printf("������ɼ�[10��] ��Enter������...:");
	for(i=0;i<10;i++)
		scanf("%f",&score[i]);
	printf("\n");
	
	aver = getAvg(score);
	printf("ƽ���ɼ�Ϊ��%5.2f\n",aver);
	printf("���鳤��Ϊ:%d",getLength(score));
	
	return 0;
} 

float getAvg(float array[10]){ // ����average���� 
	int i;
	float aver,sum=0;
	for(i=0;i<10;i++)
		sum+=array[i];   // �ۼ�ѧ���ɼ� 
	aver = sum/10;
	return aver;
	
}

int getLength(float a[]){
	int length;
	length=sizeof(a)/sizeof(a[0]);
	return length;	
}

// ��Ϊ a�Ǻ������� ���˱����� aֻ��һ��ָ��
// (��ַ ϵͳ�ڱ���������ʱ�� �ǲ�֪��a����ʾ�ĵ�ַ�ж��
// �Ĵ���ռ䣬����ֻ�Ǹ��ߺ���:һ�����ݴ洢�ռ��׵�ַ��
// ���� sizeof(a)�Ľ����ָ�����aռ�ڴ�Ĵ�С 
// 




