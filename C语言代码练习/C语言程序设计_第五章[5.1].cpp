#include<stdio.h>

int main(){
	int i = 1;
	float score1,score2,score3,score4,score5,aver;
	while(i<=50){
		printf("����������:");
		scanf("%f,%f,%f,%f,%f",&score1,&score2,&score3,&score4,&score5);
		aver = (score1 + score2 + score4 + score5)/5;
		printf("aver = %7.2f\n",aver); // �����ѧ��ƽ���ɼ�
		i++; 
	}
} 
