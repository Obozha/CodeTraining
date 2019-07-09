#include<stdio.h>
#include<limits.h>

int main(){
	int score,max;
	max=INT_MIN;
	while(scanf("%d", &score),score >= 0){
		if(score>max){
			max=score;
		}
	}
	printf("%d\n",max);
	return 0;
}
