#include<stdio.h>

int main(){
	float average(float array[10]);
	float score[10],recvAver;
	
	int i;
	printf("input 10 scores:\n");
	for(i=0;i<10;i++)
		scanf("%d",&score[i]);
	recvAver=average(score);
	printf("average score is %5.2f\n",recvAver);
	return 0;
}

float average(float array[10]){
	int i;
	float aver,sum=0;
	for(i=0;i++;i<10){
		sum+=array[i];
	}
	aver=sum/10;
	return aver;
}
