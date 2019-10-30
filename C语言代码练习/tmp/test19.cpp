//#define MAXSIZE 100
//typedef struct{
//	ElemType *elem;
//	int length;
//}SqList;

Status InitList(){
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem){
		exit(OVERFLOW);
	}
	L.length=0;
	return OK;
}

Status GetElem(SqList L,int i,ElemType &e){
	if(i<1||i>Length){
		return ERROR;
	}
	e=L.elem[i-1];
}
