typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*LinkList,LNode;

Status InitList(LinkList &L){
	L=new LNode;
	L->next=NULL;
	return OK;
}

Status GetElem(LinkList L,int i,ElemType &e){
	p=L->next;
	j=1;
	while((j<i)&&(p)){
		p=p->next;
		j++;
	}
	if(i<j||!p){
		return ERROR;
	}
	e=p->data;
	return OK;
}

LNode *LocateElem(LinkList L,ElemType e){
	p=L->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
	}
	return p;
}

Status ListInsert(LinkList L,ElemType e,int i){
	p=L;
	j=0;
	while(j<i-1&&p){
		p=p->next;
		++j
	}	
	if(i-1<j||!p){
		return ERROR;
	}
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
