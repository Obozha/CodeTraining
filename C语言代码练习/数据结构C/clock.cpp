#include<stdio.h>
#include<time.h>

clock_t start,stop;
/* clock_t��clock()�������صı������� */
double duration;
/* ��¼���⺯������ʱ�䣬����Ϊ��λ */

int main(){
	/* ���ڲ��Է�Χ�ڵ�׼������д��clock()����֮ǰ */
	start=clock();  /* ��ʼ��ʱ */
	MyFunction(); /* �ѱ��⺯���������� */
	stop=clock(); /* ֹͣ��ʱ */
	duration=((double)(stop-start))/CLK_TCK;
	/* ��������ʱ�� */
	/* �������ڲ��Է�Χ�Ĵ���д�ں��棬��������duration��ֵ */
	return 0;
}
