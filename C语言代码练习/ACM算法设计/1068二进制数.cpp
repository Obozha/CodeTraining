#include<stdio.h>

int main() {
	char ch;
	int d=0;
	// f(x) =(( (a0*x + a1)*x + a2) * x + ... an-1) * x + an
	// ����Ӹ�λ����λ�������������������Ӧ����ʽϵ��a0, a1,....��an, ��x��ֵΪ2
	// 0:48 1:49
	while(ch=getchar(),ch!='\n')
		d=d*2+(ch-'0'); // a0*x+a1(ch-'0') ����x=2

	printf("%d\n",d);
	return 0;
}

