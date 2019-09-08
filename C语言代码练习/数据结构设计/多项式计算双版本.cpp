#include<stdio.h>
#include<math.h>
#include<time.h>
clock_t start,stop;
double duration;
#define MAXN 10 /* ����ʽ���������������ʽ����+1 */ 
#define MAXK 1e7 /* ���⺯�������ô��� */ 

double f_c(int n,double a[],double x){
	int i;
	double p=a[0];
	for(i=1;i<=n;i++){
		p+=(a[i]*pow(x,i));
	}
	return p;
}

double f_s(int n,double a[],double x){
	int i;
	double p=a[n]; 
	for(i=n;i>0;i--){ 
		p=a[i-1]+x*p;
	}
	return p;
}

int main(){
	int i;
	double a[MAXN]; /* �洢����ʽ��ϵ�� */
	for(i=0;i<MAXN;i++)
		a[i]=(double)i;
	start=clock();
	for(i=0;i<MAXK;i++)
		f_c(MAXN-1,a,1.1);
	stop=clock(); // ���ص��� clock_t 
	duration=((double)stop-start)/CLK_TCK; //CLK_TCK ����ʱ��ÿ�����ߵ�ʱ�Ӵ����
	// stop-start ���ܹ��ж���ʱ�Ӵ����/����ʱ�Ӵ���� =���� 
	
	printf("ticks=%f\n",(double)(stop-start)); //  
	printf("duration1=%6.2e\n",duration);
	
	start=clock();
	for(i=0;i<MAXK;i++)
		f_s(MAXN-1,a,1.1);
	stop=clock();
	duration=((double)(stop-start)/CLK_TCK);
	printf("tick2=%f\n",(double)(stop-start));
	printf("duration2=%6.2e\n",duration);
	return 0;
}
 
