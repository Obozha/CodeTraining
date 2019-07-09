#include<stdio.h>

int main(){
	struct bs{
		unsigned a:1;
		unsigned b:3;
		unsigned c:4;
	};
	bs bit;
	bs *pbit;
	
	bit.a=1; /* 给位域赋值(应注意赋值不能超过该位域的允许范围) */
	bit.b=7; /* 给位域赋值(应注意赋值不能超过该位域的允许范围) */
	bit.c=15;/* 给位域赋值(应注意赋值不能超过该位域的允许范围) */
	printf("%d,%d,%d\n",bit.a,bit.b,bit.c); 
	/* 以整形量格式输出三个域的内容 */
	
	pbit=&bit; // 把位域变量 bit 的地址赋值给 
	pbit->a=0; /* 用指针的方式给位域a重新赋值，赋为0 */
	pbit->b&=3; // 使用了复合的位运算符 "&=", 相当于: pbit->b=bpit->b&3 
	pbit->c|=1; // 使用了符合的位运算符"|=",相当于:pbit->c=pbit->c|1,其结果为15
	
	printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);
	/* 用指针方式输出了这三个域的值 */
	 
	return 0;


} 
