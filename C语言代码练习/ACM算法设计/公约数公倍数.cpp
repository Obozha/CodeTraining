#include<stdio.h>
int calcGY(int,int);
double calcGB(int,int,int);
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("最大公约数：%d,最大公倍数：%.0lf",calcGY(a,b),calcGB(a,b,calcGY(a,b)));
} 

int calcGY(int a,int b){
	if(a>0&&b>0) {
		while(a!=b) {
			if(a>b)
				a=a-b;
			else
				b=b-a;
		}
		return a;
	}
	return 0;
}

double calcGB(int a,int b,int d){
	return (double)a*b/d;
}
