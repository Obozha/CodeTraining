#include<stdio.h>

int main() {
	int n,i;
	scanf("%d",&n);
	if(n>=2&&n<=1000) {
		for(i=2; i<n; i++)
			if(n%i==0)
				break;
		if(i<n)		// ��iС��n��ʱ��˵����ѭ��û�������������� true -> nO
			// i=n��ʱ��˵��ѭ������Ҳû���� ��������   false ->yES
			printf("No");
		else
			printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}
