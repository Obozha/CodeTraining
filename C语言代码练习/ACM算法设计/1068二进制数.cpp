#include<stdio.h>

int main() {
	char ch;
	int d=0;
	// f(x) =(( (a0*x + a1)*x + a2) * x + ... an-1) * x + an
	// 本题从高位到低位依次输出二进制数，对应多项式系数a0, a1,....，an, 而x的值为2
	// 0:48 1:49
	while(ch=getchar(),ch!='\n')
		d=d*2+(ch-'0'); // a0*x+a1(ch-'0') 其中x=2

	printf("%d\n",d);
	return 0;
}

