#include<stdio.h>

float Max,Min;
float average(float array[],int);


int main(){
	float ave,score[10];
	int i,length;
	length=sizeof(score)/sizeof(score[0]);
	
	
	printf("������ʮ������:");
	for(i=0;i<10;i++){
		scanf("%f",&score[i]);
	}
	
	ave = average(score,length);
	printf("\n");
	printf("���ֵ:%5.2f ��Сֵ:%5.2f ƽ��ֵ:%5.2f",Max,Min,ave); 
	
}
float average(float array[],int n){
	int i; 
	float aver,sum=array[0];
	Max=Min=array[0];
	for(i=1;i<n;i++){
		if(array[i]>Max) 
			Max=array[i];
		else if(array[i]<Min)
			Min=array[i];
		sum+=array[i];
	}
	aver=sum/n;
	return aver;
}
