#include<stdio.h>
#include<math.h>

int main(){
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c);
	max=a;
	if(abs(b)>abs(max)){
		max=b;
	}
	if(abs(c)>abs(max)){
		max=c;
	}
	printf("%d",max);
	return 0; 
	
}
