#include<stdio.h>

int main(){
	struct bs{
		unsigned a:1;
		unsigned b:3;
		unsigned c:4;
	};
	bs bit;
	bs *pbit;
	
	bit.a=1; /* ��λ��ֵ(Ӧע�⸳ֵ���ܳ�����λ�������Χ) */
	bit.b=7; /* ��λ��ֵ(Ӧע�⸳ֵ���ܳ�����λ�������Χ) */
	bit.c=15;/* ��λ��ֵ(Ӧע�⸳ֵ���ܳ�����λ�������Χ) */
	printf("%d,%d,%d\n",bit.a,bit.b,bit.c); 
	/* ����������ʽ�������������� */
	
	pbit=&bit; // ��λ����� bit �ĵ�ַ��ֵ�� 
	pbit->a=0; /* ��ָ��ķ�ʽ��λ��a���¸�ֵ����Ϊ0 */
	pbit->b&=3; // ʹ���˸��ϵ�λ����� "&=", �൱��: pbit->b=bpit->b&3 
	pbit->c|=1; // ʹ���˷��ϵ�λ�����"|=",�൱��:pbit->c=pbit->c|1,����Ϊ15
	
	printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);
	/* ��ָ�뷽ʽ��������������ֵ */
	 
	return 0;


} 
