#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// polynomial 多项式 
typedef struct PNode{
	float coef;			 // 系数 
	int expn;			 // 指数  exponent
	struct PNode *next;  // 指针域 
}PNode,*Polynomial; 

void CreatePolyn(Polynomial &P,int n){
	// 输入n的系数和指数，建立表示多项式的有序链表P
	P=(Polynomial)malloc(sizeof(PNode));
	Polynomial s,q,pre;
	P->next=NULL; 							 // 先建立一个带头结点的单链表
	int i;
	for(i=1;i<=n;i++){						 // 依次输入n个非零项 
		s=(Polynomial)malloc(sizeof(PNode)); // 生成新结点 
		printf("请输入系数和指数\n");
		scanf("%f %d",&s->coef,&s->expn); 	 // 输入系数和指数
		pre=P;								 // pre用于保存q的前驱 
		q=P->next;							 // q初始化，指向首元结点
		while(q&&q->expn<s->expn){
			pre=q;
			q=q->next;
		}									 // while
		s->next=q;								 // 将输入项s插到q和其前驱结点pre之间				
		pre->next=s;
	}
}	

void AddPolyn(Polynomial &Pa,Polynomial &Pb){
	// 多项式加法：Pa=Pa+Pb,利用两个多项式的结点构成“和多项式”
	Polynomial p1=Pa->next,p2=Pb->next,p3=Pa,r; // p1和p2初值分别指向pa和pb的首元结点 
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
				free(r); // 删除Pa当前结点，p1指向后一项 
				r=p2;
				p2=p2->next;
				free(r); // 删除pb当前结点，p2指向后一项 
			}
		}else if(p1->expn<p2->expn){ // Pa当前结点的指数小 
			p3->next=p1; // 将p1链在p3之后 
			p3=p1;		 // p3指向p1 
			p1=p1->next; // p1指向后一项 
		}else{
			p3->next=p2; // 将p2链在p3之后 
			p3=p2;       // p3指向p2 
			p2=p2->next; // p2指向后一项	
		}
	} 
	p3->next=p1?p1:p2; // 插入非空多项式的剩余段
	free(Pb); 
}

void TraverseList(Polynomial P){
	P=P->next; 
	int i;
	while(P){
		printf("系数是%.0f 指数是%d \n",P->coef,P->expn);
		P=P->next;
	}
}

void Unit(){
	Polynomial Pa,Pb;
	CreatePolyn(Pa,4);
	CreatePolyn(Pb,3);
	printf("Pa插入遍历\n");
	TraverseList(Pa);
	printf("Pb插入遍历\n");
	TraverseList(Pb);
	AddPolyn(Pa,Pb);
	printf("合并之后\n");
	TraverseList(Pa);
}

int main(){
	Unit();
}
