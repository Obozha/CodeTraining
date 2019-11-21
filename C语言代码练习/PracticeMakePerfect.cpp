// 顺序表的存储

#define MAXSIZE 100
typedef struct {
	ElemType *elem; // 存储空间的基地址
	int length;		// 当前长度
} SqList; 			// 顺序表结构类型为SqList

Status InitList(SqList &L) {
	// 构造一个空的顺序表L
	L.elem=new ElemType[MAXSIZE]; // 向堆内存申请空间
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	return OK;
}

// 顺序表的取值
Status GetElem(SqList L,int i,ElemType &e) {
	if(i<1||i>L.length) {
		return ERROR;
	}
	e=L.elem[i-1];
	return OK;
}

int LocateElem(SqList L,ElemType e) {
	// 在顺序表L中查找值为e的数据元素，返回其序号
	for(i=0; i<L.length; i++) {
		if(L.elem[i]==e) {
			return (i+1);
		}
	}
	return -1;
}

Status ListInsert(SqList &L,int i,ElemType e) {
	// 在顺序表L中第i个位置插入新的元素e，i的合法范围是1<=i<=L.length+1
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
	// 在顺序表L中删除第i个元素，i的合法范围是1<=i<=L.length
	if((i<1)||(i>L.length))
		return ERROR;
	for(j=i; j<=L.length-1; j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
}

typedef struct LNode {
	ElemType data;			// 结点的数据域
	struct LNode *next;		// 结点的指针域
} LNode,*LinkList;			// LinkList为指向结构体LNode的指针类型

// 单链表的初始化
Status InitList (LinkList &L) {
	// 构造一个空单链表L
	L=new LNode;			// 生成新结点作为头结点
	L->next=NULL;			// 头结点的指针域置空
	return OK;
}

Status GetElem(LinkList L,int i,ElemType &e) {
	// 带头结点的单链表L中根据序号i获取元素的值，
	// 用e返回L中第i个数据元素的值
	p=L->next;
	j=1;
	// 初始化，p指向首元结点，计数器j初值赋1
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
	// 在头结点的单链表L中查找值为e的元素
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;
}

Status ListInsert(LinkList &L,int i,ElemType e) {
	// 在带头结点的单链表L中第i个位置插入为e的新结点
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
	if(!(p->next)||(j>i-1)) {	// 当i>n或i<1时，删除位置不合理
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	return OK;
}

void CreateList_H(LinkList &L,int n) {
	// 逆位序输入n个元素的值，建立表带头结点的单链表L
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
	// 正位序输入n个元素的值，建立带表头结点的单链表L
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
	// 带头结点的双线链表L中的第i个位置之前插入元素e
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
	// 删除带头结点的双向链表L中的第i个元素
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
	n=ListLength(LB);		// 求线性表的长度
	for(i=1; i<=n; i++) {
		GetElem(LB,i,e);	// 取LB中第i个数据元素赋给e
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
		// LA和LB均为到达表尾，依次“摘取”两表中值最小的结点插入到LC的最后
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
	// 将两个递增的有序链表La和Lb合并为一个递增的有序链表Lc
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
	// 确定单链表中值最大的结点
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
	// 逆置带头结点的单链表L
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
	// 删除递增有序链表L中值大于mink且小于maxk的所有元素
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

// 顺序栈的存储结构
#define MAXSIZE 100 // 顺序栈存储空间的初始分配量 
typedef struct {
	SElemType *base; // 栈底指针
	SElemType *top;	 // 栈顶指针
	int stacksize;	 // 栈可用最大容量
} SqStack;

Status InitStack(SqStack &S) {
	S.base=new SElemType[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW) ;
	S.stacksize=MAXSIZE;
	return OK;
}

Status Push(SqStack &S,SElemType e) {
	// 插入e为新的栈顶元素
	if(S.top-S.base==S.stacksize)
		return ERROR;
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e) {
	// 删除S的栈顶的元素，用e返回其值
	if(S.top==S.base)
		return ERROR;	// 栈空 
	e=*--S.top;			// 栈顶指针减1，将栈顶元素赋给e 
	return OK;
}

SElemType GetTop(SqStack S){
	// 返回S的栈顶元素，不修改栈顶指针
	if(S.top!=S.base) // 栈非空
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
	if(S!=NULL){		// 栈非空 
		return S->data; // 返回栈顶元素的值，栈顶指针不变 
	}
}

// 循环队列 
#define MAXQSIZE 100 // 队列可能达到的最大长度
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
	// 中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	} 
}

void InOrderTraverse(BiTree T){
	// 中序遍历二叉树T的非递归算法
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
	// 按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
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
	// 计算二叉树T的深度
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
	// 对图G做深度优先遍历
	for(v=0;v<G.vernum;v++){
		visited[v]=false;
	} 
	for(v=0;v<G.vernum;v++){
		if(!visited[v]){
			DFS(G,v);
			// 对尚未访问的顶点调用DFS 
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
	// 图G为邻接矩阵类型
	cout<<v;
	visited[v]=true;
	for(w=0;w<G.vexnum;w++){
		if(G.arcs[v][w]!=0 && !visited[w])
			DFS(G,w);
	} 
}

void BFSTraverse(Graph G){
	// 按广度优先非递归遍历图G
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
	// 按广度遍历非递归遍历图G
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
