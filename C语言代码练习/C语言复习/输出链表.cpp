#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student{		// �����ṹ������struct Student 
	long num;
	float score;
	struct Student *next;
};

int n;	// ȫ�ֱ���n
void print(struct Student* head){ // ����print���� 
	struct Student* p;	// �ں����ж���struct Student���͵ı���p
	printf("\nNow,These %d records are:\n",n); 
	p=head;
	if(head!=NULL){
		do{
			printf("%ld %5.1f\n",p->num,p->score);
			p=p->next; 
		}while(p!=NULL); //��p����"�յ�ַ" 
	}
} 
