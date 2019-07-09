#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// polynomial ����ʽ 
typedef struct PNode{
	float coef;			 // ϵ�� 
	int expn;			 // ָ��  exponent
	struct PNode *next;  // ָ���� 
}PNode,*Polynomial; 

void CreatePolyn(Polynomial &P,int n){
	// ����n��ϵ����ָ����������ʾ����ʽ����������P
	P=(Polynomial)malloc(sizeof(PNode));
	Polynomial s,q,pre;
	P->next=NULL; 							 // �Ƚ���һ����ͷ���ĵ�����
	int i;
	for(i=1;i<=n;i++){						 // ��������n�������� 
		s=(Polynomial)malloc(sizeof(PNode)); // �����½�� 
		printf("������ϵ����ָ��\n");
		scanf("%f %d",&s->coef,&s->expn); 	 // ����ϵ����ָ��
		pre=P;								 // pre���ڱ���q��ǰ�� 
		q=P->next;							 // q��ʼ����ָ����Ԫ���
		while(q&&q->expn<s->expn){
			pre=q;
			q=q->next;
		}									 // while
		s->next=q;								 // ��������s�嵽q����ǰ�����pre֮��				
		pre->next=s;
	}
}	

void AddPolyn(Polynomial &Pa,Polynomial &Pb){
	// ����ʽ�ӷ���Pa=Pa+Pb,������������ʽ�Ľ�㹹�ɡ��Ͷ���ʽ��
	Polynomial p1=Pa->next,p2=Pb->next,p3=Pa,r; // p1��p2��ֵ�ֱ�ָ��pa��pb����Ԫ��� 
	float sum;
	while(p1&&p2){
		if(p1->expn==p2->expn){
		    sum=p1->coef+p2->coef;
			if(sum!=0){
				p1->coef=sum; 
				p3->next=p1;
				p3=p1;
				p1=p1->next;
				r=p2;
				p2=p2->next;
				free(r);
			}else{
				r=p1;
				p1=p1->next;
				free(r); // ɾ��Pa��ǰ��㣬p1ָ���һ�� 
				r=p2;
				p2=p2->next;
				free(r); // ɾ��pb��ǰ��㣬p2ָ���һ�� 
			}
		}else if(p1->expn<p2->expn){ // Pa��ǰ����ָ��С 
			p3->next=p1; // ��p1����p3֮�� 
			p3=p1;		 // p3ָ��p1 
			p1=p1->next; // p1ָ���һ�� 
		}else{
			p3->next=p2; // ��p2����p3֮�� 
			p3=p2;       // p3ָ��p2 
			p2=p2->next; // p2ָ���һ��	
		}
	} 
	p3->next=p1?p1:p2; // ����ǿն���ʽ��ʣ���
	free(Pb); 
}

void TraverseList(Polynomial P){
	P=P->next; 
	int i;
	while(P){
		printf("ϵ����%.0f ָ����%d \n",P->coef,P->expn);
		P=P->next;
	}
}

void Unit(){
	Polynomial Pa,Pb;
	CreatePolyn(Pa,4);
	CreatePolyn(Pb,3);
	printf("Pa�������\n");
	TraverseList(Pa);
	printf("Pb�������\n");
	TraverseList(Pb);
	AddPolyn(Pa,Pb);
	printf("�ϲ�֮��\n");
	TraverseList(Pa);
}

int main(){
	Unit();
}
