#include<stdio.h>

void average(float*,int);
void search(float (*p)[4],int n);

int main(){
	float score[3][4]={{65,67,70,60},{80,87,90,81},{90,99,100,98}};
	average(*score,12);		// ��12��������ƽ����
	search(score,2); 		// �����Ϊ2��ѧ���ĳɼ� 
	return 0; 
}

void average(float *p,int n){ // ������ƽ���ɼ��ĺ��� 
	float *p_end;
	float sum=0,aver;
	p_end=p+n;				// n��ֵΪ12ʱ��p_endֵָ��p+12 p+11��ʵ����ĩβ�� 
	for(;p<p_end;p++)		// ��p_end ָ��p+12 ���˳�ѭ�� Ҳ����P+11�����һ�� 
		sum=sum+(*p);
	aver=sum/n;
	printf("average =%5.2f \n",aver);
}

void search(float (*p)[4],int n){	//p��ָ�����4��Ԫ�ص�һά�����ָ�� 
	int i;
	printf("The score of No.%d are:\n",n);
	for(i=0;i<4;i++)
		printf("%5.2f ",*(*(p+n)+i));
	printf("\n");
}
