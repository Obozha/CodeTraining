#include<stdio.h>
int main(){
	int n,i,j;
	double s;
	scanf("%d",&n);
	s=1.0;
	for(i=1;i<=n;i++){
		s=s*i;
		while(s>=10){ // ±ßÀÛ³Ë±ßÅ×¸öÎ»Êý 
			s=s/10;
		}
	}
	printf("%0.lf\n",s);
}
