#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)

struct Student{
	long num;
	float score;
	struct Student *next;
};

int n; // nΪȫ�ֱ��������ļ�ģ���и������к�������ʹ����
struct Student *creat(void){
	// ���庯�����˺�������һ��ָ������ͷ��ָ�� 
	struct Student *head;
	struct Student *p1,*p2;
	n=0;
	p1=p2=(struct Student*)malloc(LEN); // ����һ���µ�Ԫ 
	scanf("%ld %f",&p1->num,&p1->score);
	// �����1��ѧ����ѧ�źͳɼ�
	head=NULL;
	while(p1->num!=0){
		n=n+1;
		if(n==1){
			head=p1;
		}else{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct Student*)malloc(LEN);
		// ���ٶ�̬������������ʼ��ַ����p1
		scanf("%ld %f",&p1->num,&p1->score);
		// ��������ѧ����ѧ�źͳɼ� 
	} 
	p2->next=NULL;
	return head;
}

int main(){
	struct Student *pt;
	pt=creat(); // �������������һ�����ĵ�ַ
	printf("\nnum:%ld \nscore:%5.1f\n",pt->num,pt->score);
	return 0;
}
 
