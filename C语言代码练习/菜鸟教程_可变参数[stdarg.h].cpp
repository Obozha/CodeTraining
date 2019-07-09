#include<stdio.h>
#include<stdarg.h>

double average(int sum,...);

int main(){
	printf("Average of 2,3,4,5 = %f\n",average(4, 2,3,4,5));
		printf("Average of 5,10,15 = %f\n",average(3, 5,10,15));
}

// ����func()���һ������д��ʡ�Ժţ����������(...)
// ʡ�Ժ�֮ǰ���Ǹ�������int,������Ҫ���ݵĿɱ������������Ϊ��ʹ��������� ����stdarg.hͷ�ļ�

//  va_list���ͱ��� ����������stdarg.hͷ�ļ��ж����
// ʹ�� int ������va_start������ʼ�� va_list����Ϊһ�������б���va_start����stdarg.hͷ�ļ��ж����
// ʹ��va_arg���va_list���������ʲ����б��е�ÿһ��
// ʹ�ú�va_end��������va_list�������ڴ档 
 

double average(int num,...){
	va_list valist;
	double sum = 0.0;
	int i;
	
	
	
	/* Ϊnum��������ʼ��valist */
	va_start(valist,num);
	
	/* �������и���valist�Ĳ��� */
	for(i=0;i<num;i++){
		sum+=va_arg(valist,int);
	}
	/* ����Ϊ valist �������ڴ� */
	va_end(valist);
	return sum/num;
}
