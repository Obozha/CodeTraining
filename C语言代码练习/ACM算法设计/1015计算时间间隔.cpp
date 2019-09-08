#include<stdio.h>

int main() {
	int t,t1,t2,h1,h2,m1,m2,s1,s2,a,b,c;
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	t1=h1*3600+m1*60+s1;
	// t1精确到秒 
	t2=h2*3600+m2*60+s2;
	// t2精确到秒 
	if(t1<t2)
		t=t2-t1;
	else 
		t=t1-t2;
	printf("%d",t);
	return 0;
}
