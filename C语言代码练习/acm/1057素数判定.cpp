#include<stdio.h>

int main() {
	int n,i;
	scanf("%d",&n);
	if(n>=2&&n<=1000) {
		for(i=2; i<n; i++)
			if(n%i==0)
				break;
		if(i<n)		// 当i小于n的时候说明在循环没结束就跳出来了 true -> nO
			// i=n的时候说明循环结束也没跳出 即是素数   false ->yES
			printf("No");
		else
			printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}
