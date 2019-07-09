#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct Student)

struct Student{
	long num;
	float score;
	struct Student *next;
};

int n;
struct Student* creat(){
	struct Student *head=NULL,*p1,*p2;
	n=0;
	p1=p2=(struct Student*)malloc(LEN);
	scanf("%ld %f",&p1->num,&p1->score);
	while(p1->num!=0){
		n++;
		if(n==1){
			head=p1;
		}else{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct Student*)malloc(LEN);
		scanf("%ld %f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head; 
}

void print(struct Student *head){
	struct Student *p=head;
	printf("\n Now,These %d records are:\n",n);
	if(head!=NULL){
		while(p!=NULL){
			printf("%ld %5.1f\n",p->num,p->score);
			p=p->next;
		}
	}
}

int main(){
	struct Student *head=creat();
	print(head);
	return 0;
}
