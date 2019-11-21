// ˳���Ĵ洢

#define MAXSIZE 100
typedef struct {
	ElemType *elem; // �洢�ռ�Ļ���ַ
	int length;		// ��ǰ����
} SqList; 			// ˳���ṹ����ΪSqList

Status InitList(SqList &L) {
	// ����һ���յ�˳���L
	L.elem=new ElemType[MAXSIZE]; // ����ڴ�����ռ�
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	return OK;
}

// ˳����ȡֵ
Status GetElem(SqList L,int i,ElemType &e) {
	if(i<1||i>L.length) {
		return ERROR;
	}
	e=L.elem[i-1];
	return OK;
}

int LocateElem(SqList L,ElemType e) {
	// ��˳���L�в���ֵΪe������Ԫ�أ����������
	for(i=0; i<L.length; i++) {
		if(L.elem[i]==e) {
			return (i+1);
		}
	}
	return -1;
}

Status ListInsert(SqList &L,int i,ElemType e) {
	// ��˳���L�е�i��λ�ò����µ�Ԫ��e��i�ĺϷ���Χ��1<=i<=L.length+1
	if((i<1)||(i>L.length+1)) {
		return ERROR;
	}
	if(L.length==MAXSIZE) {
		return ERROR;
	}
	for(j=L.length-1; j>=i-1; j--) {
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i-1]=e;
	++L.length;
	return OK;
}

Status ListDelete(SqList &L,int i) {
	// ��˳���L��ɾ����i��Ԫ�أ�i�ĺϷ���Χ��1<=i<=L.length
	if((i<1)||(i>L.length))
		return ERROR;
	for(j=i; j<=L.length-1; j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
}

typedef struct LNode {
	ElemType data;			// ����������
	struct LNode *next;		// ����ָ����
} LNode,*LinkList;			// LinkListΪָ��ṹ��LNode��ָ������

// ������ĳ�ʼ��
Status InitList (LinkList &L) {
	// ����һ���յ�����L
	L=new LNode;			// �����½����Ϊͷ���
	L->next=NULL;			// ͷ����ָ�����ÿ�
	return OK;
}

Status GetElem(LinkList L,int i,ElemType &e) {
	// ��ͷ���ĵ�����L�и������i��ȡԪ�ص�ֵ��
	// ��e����L�е�i������Ԫ�ص�ֵ
	p=L->next;
	j=1;
	// ��ʼ����pָ����Ԫ��㣬������j��ֵ��1
	while(p&&j<i) {
		p=p->next;
		j++;
	}
	if(!p||j>i) {
		return ERROR;
	}
	e=p->data;
	return OK;
}

LNode *LocateElem(LinkList L,ElemType e) {
	// ��ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;
}

Status ListInsert(LinkList &L,int i,ElemType e) {
	// �ڴ�ͷ���ĵ�����L�е�i��λ�ò���Ϊe���½��
	p=L;
	j=0;
	while(p&&(j<i-1)) {
		p=p->next;
		++j;
	}

	if(!p||j>i-1)
		return ERROR;
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status ListDelete(LinkList &L,int i) {
	p=L;
	j=0;
	while((p->next)&&(j<i-1)) {
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1)) {	// ��i>n��i<1ʱ��ɾ��λ�ò�����
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	return OK;
}

void CreateList_H(LinkList &L,int n) {
	// ��λ������n��Ԫ�ص�ֵ���������ͷ���ĵ�����L
	L=new LNode;
	L->next=NULL;
	for(i=0; i<n; i++) {
		p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}

void CreateList_R(LinkList &L,int n) {
	// ��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	L=new LNode;
	L->next=NULL;
	r=L;
	for(i=0; i<n; i++) {
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode,*DuLinkList;

Status ListInsertDuL(DuLinkList &L,int i,ElemType e) {
	// ��ͷ����˫������L�еĵ�i��λ��֮ǰ����Ԫ��e
	if(!(p=GetElem_DuL(L,i)))
		return ERROR;
	s=new DuLNode;
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return OK;
}

Status ListDelete_DuL(DuLinkList &L,int i) {
	// ɾ����ͷ����˫������L�еĵ�i��Ԫ��
	if(!(p=GetElem_DuL(L,i))) {
		return ERROR;
	}
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
	return OK;
}

void MergeList(List &LA,List LB) {
	m=ListLength(LA);
	n=ListLength(LB);		// �����Ա�ĳ���
	for(i=1; i<=n; i++) {
		GetElem(LB,i,e);	// ȡLB�е�i������Ԫ�ظ���e
		if(!LocateElem(LA,e)) {
			ListInsert(LA,++m,e);
		}
	}
}

void MergeList_Sq(SqList LA,SqList LB,SqList &LC) {
	LC.length=LA.length+LB.length;
	LC.elem=new ElemType[LC.length];

	pa=LA.elem;
	pb=LB.elem;
	pc=LC.elem;

	pa_last=LA.elem+LA.length-1;
	pb_last=LB.elem+LB.length-1;

	while((pa<=pa_last)&&(pb<=pb_last)) {
		if(*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++;
	}
}

void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC) {
	pa=LA->next;
	pb=LB->next;
	pc=LC=LA;
	while(pb&&pb) {
		// LA��LB��Ϊ�����β�����Ρ�ժȡ��������ֵ��С�Ľ����뵽LC�����
		if(pa->data<=pb->data) {
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		} else {
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	delete LB;
}

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc) {
	// ��������������������La��Lb�ϲ�Ϊһ����������������Lc
	pa=La->next;
	pb=Lb->next;
	pc=Lc=La;
	while(pa&&pb) {
		if(pa->data<pb->data) {
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		} else if(pa->data>pb->data) {
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		} else {
			pc->next=pa;
			pc=pa;
			pa=pa->next;
			q=pb->next;
			delete pb;
			pb=q;
		}
	}
	pc->next=pa?pa:pb;
	delete Lb;
}

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc) {
	pa=La->next;
	pb=Lb->next;
	pc=Lc=La;
	Lc->next=NULL;
	while(pa||pb) {
		if(!pa) {
			q=pb;
			pb=pb->next;
		} else if(!pb) {
			q=pa;
			pa=pa->next;
		} else if(pa->data<=pb->data) {
			q=pa;
			pa=pa->next;
		} else {
			q=pb;
			pb=pb->next;
		}
		q->next=Lc->next;
		Lc->next=q;
	}
	delete Lb;
}

ElemType Max(LinkList L) {
	// ȷ����������ֵ���Ľ��
	if(L->next==NULL)
		return NULL;
	pmax=L->next;
	p=L->next->next;
	while(p!=NULL) {
		if(p->data>pmax->data)
			pmax=p;
		p=p->next;
	}
	return (pmax->data);
}

void Inverse(LinkList &L) {
	// ���ô�ͷ���ĵ�����L
	p=L->next;
	L->next=NULL;
	while(p) {
		q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
}

void DeleteMinMax(LinkList &L,int mink,int maxk) {
	// ɾ��������������L��ֵ����mink��С��maxk������Ԫ��
	p=L->next;
	while(p&&p->data<=mink) {
		pre=p;
		p=p->next;
	}

	while(p&&p->data<maxk)
		p=p->next;
	q=pre->next;
	pre->next=p;
	while(q!=p) {
		s=q->next;
		delete q;
		q=s;
	}
}

// ˳��ջ�Ĵ洢�ṹ
#define MAXSIZE 100 // ˳��ջ�洢�ռ�ĳ�ʼ������ 
typedef struct {
	SElemType *base; // ջ��ָ��
	SElemType *top;	 // ջ��ָ��
	int stacksize;	 // ջ�����������
} SqStack;

Status InitStack(SqStack &S) {
	S.base=new SElemType[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW) ;
	S.stacksize=MAXSIZE;
	return OK;
}

Status Push(SqStack &S,SElemType e) {
	// ����eΪ�µ�ջ��Ԫ��
	if(S.top-S.base==S.stacksize)
		return ERROR;
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e) {
	// ɾ��S��ջ����Ԫ�أ���e������ֵ
	if(S.top==S.base)
		return ERROR;	// ջ�� 
	e=*--S.top;			// ջ��ָ���1����ջ��Ԫ�ظ���e 
	return OK;
}

SElemType GetTop(SqStack S){
	// ����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if(S.top!=S.base) // ջ�ǿ�
		return *(S.top-1); 
}

typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

Status InitStack(LinkStack &S){
	S=NULL;
	return OK;
}

Status Push(LinkStack &S,SElemType e){
	p=new StackNode;
	p->data=e;
	p->next=S;
	S=p;
	return OK;
}             

Status Pop(LinkStack &S,SElemType &e){
	if(S==NULL)
		return ERROR;
	e=S->data;
	p=S;
	S=S->next;
	delete p;
	return OK;
}

SElemType GetTop(LinkStack S){
	if(S!=NULL){		// ջ�ǿ� 
		return S->data; // ����ջ��Ԫ�ص�ֵ��ջ��ָ�벻�� 
	}
}

// ѭ������ 
#define MAXQSIZE 100 // ���п��ܴﵽ����󳤶�
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXQSIZE];
	if(!Q.base){
		exit(OVERFLOW);
	}
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}         

Status EnQueue(SqQueue &Q,QElemType e){
	// 
	if((Q.rear+1)%MAXQSIZE==Q.front){
		return ERROR;
	}
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return OK;
}

Status DeQueue(SeQueue &Q,QElemType &e){
	if(Q.front==Q.rear){
		return ERROR;
	}
	e=Q.base[Q.front]; 
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}

SElemType GetHead(SqQueue Q){
	if(Q.front!=Q.rear){
		return Q.base[Q.front];
	}
}

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	Q.front->next=NULL;
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e){
	p=new QNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
	if()
}

#define MAXSIZE 100
typedef struct {
	ElemType *elem;
	int length;
}SqList;

Status InitList(SqList &L){
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem){
		exit(OVERFLOW);
	}
	L.length=0;
	return OK;
}

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InOrderTraverse(BiTree T){
	// �������������T�ĵݹ��㷨
	if(T){
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	} 
}

void InOrderTraverse(BiTree T){
	// �������������T�ķǵݹ��㷨
	InitStack(S);
	p=T;
	q=new BiTNode;
	while(p||!StackEmpty(S)){
		if(p){
			Push(S,p);
			p=p->next;
		}else{
			Pop(S,q);
			cout<<q->data;
			p=q->rchild;
		}
	} 
}

void CreateBiTree(BiTree &T){
	// �������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	cin>>ch;
	if(ch=='#'){
		T=NULL;
	} else{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

int Depth(BiTree T){
	// ���������T�����
	if(T==NULL)
		return 0;
	else{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n){
			return (m+1);
		}else{
			return (n+1);
		}
	} 
}

int NodeCount(BiTree T){
	if(T==NULL){
		return 0;
	}else{
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
	}
}


typedef struct BiTNode{
	TElemType data;
	struct 	BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
}

void InOrderTraverseFDG(BiTree T){
	InitStack(S);
	p=T;
	q=new BiTNode;
	while(p||!EmptyStack(S)){
		if(p){
			Push(p);
			p=p->lchild;
		}else{
			Pop(S,q);
			cout<<q->data;
			p=q->rchild;
		}
	}
}

void CreateBiTNode(BiTree &T){
	cin>>ch;
	if(ch=='#'){
		T=NULL;
	}else{
		T=new BiTNode;
		T->data=ch;
		CreateBiTNode(T->lchild);
		CreateBiTNode(T->rchild);
	}
}

int Depth(BiTree T){
	if(T==NULL){
		return 0;
	}else{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n){
			return (m+1);
		}else{
			return (n+1);
		}
	}
}

int CountNode(BiTree T){
	if(T==NULL){
		return 0;
	}else{
		return CountNode(T->lchild)+CountNode(T->rchild)+1;
	}
}

int CountLeafNode(BiTree T){
	if(T==NULL){
		return 0;
	}else if(T->lchild==NULL && T->rchild==NULL){
		return 1;
	}else{
		return CountLeafNode(T->rchild)+CountLeafNode(T->lchild);
	}
}

#define MAXInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum]l
	int vexnum,arcnum;
}AMGraph;

void DFSTraverse(Graph G){
	// ��ͼG��������ȱ���
	for(v=0;v<G.vernum;v++){
		visited[v]=false;
	} 
	for(v=0;v<G.vernum;v++){
		if(!visited[v]){
			DFS(G,v);
			// ����δ���ʵĶ������DFS 
		}
	}
}

void DFS(ALGraph G,int v){
	cout<<v;
	visited[v]=true;
	p=G.vertices[v].fisrtarc;
	while(p){
		w=p->adjvex;
		if(!visited[w]){
			DFS(G,w);
		}
		p=p->next;
	}
}

void DFS(AMGraph G,int v){
	// ͼGΪ�ڽӾ�������
	cout<<v;
	visited[v]=true;
	for(w=0;w<G.vexnum;w++){
		if(G.arcs[v][w]!=0 && !visited[w])
			DFS(G,w);
	} 
}

void BFSTraverse(Graph G){
	// ��������ȷǵݹ����ͼG
	for(v=0;v<G.vexnum;v++){
		visited[v]=false;
	} 
	for(v=0;v<G.vexnum;v++){
		if(!visited[v]){
			BFS(G,v);
		}
	}
}

void BFS(Graph G,int v){
	// ����ȱ����ǵݹ����ͼG
	InitQueue(Q);
	cout<<v;
	visited[v]=true;
	EnQueue(Q,v);
	while(!QueueEmpty(Q)){
		DeQueue(Q,u);
		w=p->adjvex;
		if(!visited[w]){
			cout<<w;
			visited[w]=true;
			EnQueue(Q,w);
			p=p->next;
		}
	} 
}



#define MAXINT 32767
#define MVNum 100
typedef char VexTexType;
typedef int ArcType;
typedef struct {
	VexTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum]
	int vexnum,arcnum;
}AMGraph;

#define MVNum 100				 
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	Other info;
}ArcNode;

typedef struct VNode{
	VexTexType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;
 
#define MAXINT 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

typedef struct{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int arcnum,vexnum;
}AMGraph;

#define MVNum 100
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode{
	VexTexType data;
	ArcNode *fisrtarc;
}VNode,AdjList[MVNum];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

void DFSTraverse(Graph G){
	for(v=0;v<G.vexnum;v++){
		visited[v]=false;
	}
	for(v=0;v<G.vexnum;v++){
		if(!visited[v]){
			DFS(G,w);
		}
	}
}

void DFSTraverse(Graph G){
	for(v=0;v<G.vexnum;v++){
		visited[v]=false;
	}
	for(v=0;v<G.vexnum;v++){
		if(!visited[v]){
			DFS(G,v);
		}
	}
}

void DFS(ALGraph G,int v){
	cout<<v;
	visited[v]=true;
	p=G.vertices[v].fisrtarc;
	while(p!=NULL){
		w=p->adjvex;
		if(!visited[w]){
			DFS(G,w);
		}
		p=p->next;
	}
}

void DFS(AMGraph G,int v){
	cout<<v;
	visited[v]=true;
	for(w=0;w<G.vexnum;w++){
		if(G.arcs[v][w]!=0 && (!visited[w]))
			DFS(G,w);
	}
}

void DFS(ALGraph G,int v){
	cout<<v;
	visited[v]=true;
	p=G.vertics[v].firstarc;
	while(p!=NULL){
		w=p->adjvex;
		if(!visited[w]){
			DFS(G,w);
		}
		p=p->next;
	}
}

void DFS(AMGraph G,int v){
	cout<<v;
	visited[v]=true;
	for(w=0;w<G.vexnum;w++){
		if(G.arcs[v][w]!=0 && (!visited[w])){
			DFS(G,w)p
		}
	}
} 
