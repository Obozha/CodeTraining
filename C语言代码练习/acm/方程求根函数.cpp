#include<stdio.h>
#include<math.h>

int calc(int a,int b,int c); 

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	calc(a,b,c);
}

int calc(int a,int b,int c){
	int disc=b*b-4*a*c;
	if(disc>0){
		printf("��1Ϊ%.0lf����2Ϊ%.0lf",(-b-sqrt((double)disc))/2*a,(-b+sqrt((double)disc))/2*a);
	}else if(disc==0){
		printf("��Ϊ%.0lf",(-b-sqrt((double)disc))/2*a);
	}else if(disc<0){
		printf("û��");
	}
}
