#include<stdio.h>

// typedef vs #define
// #define ��Cָ�����Ϊ�����������ͱ�������typedef����

// typedef ������Ϊ���Ͷ���������� #define ��������Ϊ���Ͷ������ Ҳ��Ϊ��ֵ������
// ���������Զ���1ΪONE
// typedef ���ɱ�����ִ�н��͵ģ�#define�������Ԥ���������д���ġ� 

#define TRUE 1
#define FALSE 0

int main(){
	printf("TRUE��ֵ��%d\n",TRUE);
	printf("TRUE��ֵ��%d\n",FALSE);

}
