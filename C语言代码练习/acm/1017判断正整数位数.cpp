#include<stdio.h>
#include<math.h>

int function(int);
int main() {
	int n;
	scanf("%d",&n);
	printf("%d",function(n));
}

int function(int a) { //�ж�һ�����Ǽ�λ��
	int n=0;
	while (a) {
		a = a / 10;
		n++;
	}
	return n;
}

