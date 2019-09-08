#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void b_s(int n){
	int i;
	for(i=1;i<=n;i++){
		printf(" ");
	}
	printf("*");
}

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=-(n-1);i<=n-1;i++){
		b_s(abs(i));
		if(i!=-(n-1)&&i!=n-1)
			b_s((n - abs(i) - 1)*2 - 1);
		printf("\n");
	}
	return 0;
}


