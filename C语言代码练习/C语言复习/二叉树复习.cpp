/*
	±¾ÊµÑéÖ÷ÒªÊµÏÖ¶ş²æÊ÷µÄ»ù±¾²Ù×÷£¬¶ş²æÊ÷ÖĞ½áµãÖµµÄÀàĞÍÎªchar
	±¾ÊµÑéÖ÷ÒªÊµÏÖ5¸ö²Ù×÷£º
	1¡¢void CreatBitree(BiTree &T)  //ÊäÈë¶ş²æÊ÷µÄÏÈĞò±éÀúĞòÁĞ£¨¿ÕÊ÷ÓÃ×Ö·û'#'±íÊ¾£©£¬´´½¨¶ş²æÁ´±íT
	2¡¢void InOrderTraverse(BiTree T)   //ÖĞĞò±éÀú¶ş²æÊ÷T
	3¡¢void PreOrderTraverse(BiTree T)  //ÏÈĞò±éÀú¶ş²æÊ÷T
	4¡¢void PostOrderTraverse(BiTree T)  //ºóĞò±éÀú¶ş²æÊ÷T
	5¡¢bool SearchTree(BiTree T,char ch,BiTree &p)  //ÔÚ¶ş²æÊ÷TÖĞ²éÕÒÖµÎªchµÄ½áµã£¬²éÕÒ³É¹¦£¬º¯Êı·µ»Øtrue,pÖ¸Ïò¸Ã½áµã,·ñÔòº¯Êı·µ»Øfalse£¬pÎª¿Õ
	6¡¢int Depth(BiTree T) //Çó¶ş²æÊ÷TµÄÉî¶È
	7¡¢int NodeCount(BiTree T)  //Çó¶ş²æÊ÷TÖĞ½áµãµÄ¸öÊı
	8¡¢int LeafCount(BiTree T)  //Çó¶ş²æÊ÷TÖĞÒ¶×Ó½áµãµÄÊıÁ¿
	9¡¢int NodeCount1(BiTree T)  //Çó¶ş²æÊ÷TÖĞ¶ÈÎª1µÄ½áµãµÄÊıÁ¿
	10¡¢int NodeCount2(BiTree T)   //Çó¶ş²æÊ÷TÖĞ¶ÈÎª2µÄ½áµãµÄÊıÁ¿
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//¶ş²æÁ´±í½á¹¹
typedef struct BiTNode {
	char data;      //Êı¾İÓò,´æ·Å½áµãÖµ
	struct BiTNode *lchild,*rchild;  //×óÓÒº¢×ÓÖ¸Õë
} BiTNode,*BiTree; // ¶ş²æÁ´±í
//ÊäÈë¶ş²æÊ÷µÄÏÈĞò±éÀúĞòÁĞ£¨¿ÕÊ÷ÓÃ×Ö·û'#'±íÊ¾£©£¬´´½¨¶ş²æÁ´±íT
void CreatBitree(BiTree &T) {
	// ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	// °´ÏÈĞò´ÎĞòÊäÈë¶ş²æÊ÷ÖĞ½áµãµÄÖµ£¨Ò»¸ö×Ö·û£©£¬´´½¨¶ş²æÊ÷±íÊ¾µÄ¶ş²æÊ÷T
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;		// µİ¹é½áÊø½¨Á¿ÕÊ÷
	else {
		T=(BiTree)malloc(sizeof(BiTNode));	// Éú³É¸¸ù½áµã
		T->data=ch; 			// ¸ù½áµãÊı¾İÓòÖÃÎªch
		CreatBitree(T->lchild);	// µİ¹é´´½¨×ó×ÓÊ÷
		CreatBitree(T->rchild); // µİ¹é´´½¨ÓÒ×ÓÊ÷
	}

}

//Çó¶ş²æÊ÷TÖĞÖµÎªchµÄ½áµãµÄ²ã´Î£¬½á¹ûÓÃp±íÊ¾£¬curlevel±íÊ¾µ±Ç°TËùÔÚµÄ²ãÊı£¬
//ÇóÖµ³É¹¦·µ»Øtrue,Ê§°Ü·µ»Øfalse
bool level(BiTree T,char ch,int curlevel,int &p) {
	if(T==NULL)  //ÈôTÎª¿ÕÊ÷£¬·µ»Øfalse
		return false;
	if(T->data==ch) {  //ÈôTµÄÖµÎªch,Ôò½áµã²ãÊıpÎªcurlevel
		p=curlevel;
		return true;
	} else { //ÈôTµÄÖµÎªch,ÔòÏÈÔÚTµÄ×ó×ÓÊ÷ÖĞÇóch½áµãµÄ²ãÊı£¬Èôch½áµã²»ÔÚTµÄ×ó×ÓÊ÷ÖĞ£¬ÔÙÔÚTµÄÓÒ×ÓÊ÷ÖĞÇóch½áµãµÄ²ãÊı
		if(level(T->lchild,ch,curlevel+1,p))
			return true;
		else
			return level(T->rchild,ch,curlevel+1,p);
	}
}

//ÖĞĞò±éÀú¶ş²æÊ÷T£¬Êä³öÆäÖĞĞò±éÀúĞòÁĞ
void InOrderTraverse(BiTree T) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	// ÖĞĞò±éÀú¶ş²æÊ÷TµÄµİ¹éËã·¨
	if(T) {
		InOrderTraverse(T->lchild); // ÖĞĞò±éÀú×ó×ÓÊ÷
		printf("%c ",T->data);
		InOrderTraverse(T->rchild); // ÖĞĞò±éÀúÓÒ×ÓÊ÷
	}
}

//ÏÈĞò±éÀú¶ş²æÊ÷T£¬Êä³öÆäÏÈĞò±éÀúĞòÁĞ
void PreOrderTraverse(BiTree T) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	if(T) {
		printf("%c ",T->data);
		PreOrderTraverse(T->lchild); // ÖĞĞò±éÀú×ó×ÓÊ÷
		PreOrderTraverse(T->rchild); // ÖĞĞò±éÀúÓÒ×ÓÊ÷
	}
}

//ºóĞò±éÀú¶ş²æÊ÷T£¬Êä³öÆäºóĞò±éÀúĞòÁĞ
void PostOrderTraverse(BiTree T) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	if(T) {
		PostOrderTraverse(T->lchild); // ÖĞĞò±éÀú×ó×ÓÊ÷
		PostOrderTraverse(T->rchild); // ÖĞĞò±éÀúÓÒ×ÓÊ÷
		printf("%c ",T->data);
	}
}

bool flag=false;
//ÔÚ¶ş²æÊ÷TÖĞ²éÕÒÖµÎªchµÄ½áµã£¬²éÕÒ³É¹¦£¬º¯Êı·µ»Øtrue,pÖ¸Ïò¸Ã½áµã,·ñÔòº¯Êı·µ»Øfalse£¬pÎª¿Õ
void SearchTree(BiTree T,char ch,BiTree &p) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	if(T) {
		if(T->data==ch) {
			p=T;
			flag=true;
		}
		SearchTree(T->lchild,ch,p);
		SearchTree(T->rchild,ch,p);
	}
}

//Çó¶ş²æÊ÷TµÄÉî¶È
int Depth(BiTree T) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	int m,n;
	if(T==NULL)
		return 0; 		// Èç¹ûÊÇ¿ÕÊ÷£¬Éî¶ÈÎª0£¬µİ¹é½áÊø
	else {
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return (m+1);
		else
			return (n+1);
	}

	return 0;  //²¹³äÍê¸Ã²Ù×÷ºó£¬ÇëĞŞ¸Ä´ËĞĞ´úÂë
}

//Çó¶ş²æÊ÷TÖĞ½áµã×ÜÊı
int NodeCount(BiTree T) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	if(T==NULL)
		return 0;
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
	return 0;  //²¹³äÍê¸Ã²Ù×÷ºó£¬ÇëĞŞ¸Ä´ËĞĞ´úÂë
}

//Çó¶ş²æÊ÷TÖĞÒ¶×Ó½áµã×ÜÊı
int LeafCount(BiTree T) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	// ÏÈĞò±éÀú¶ş²æÊ÷£¬Çó¶ş²æÊ÷ÖĞÒ¶×Ó½áµãµÄÊıÄ¿
	int m,n; // m,n·Ö±ğ±íÊ¾×óÓÒ×ÓÊ÷ÖĞÒ¶×ÓµÄÊıÄ¿
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	else {
		m=LeafCount(T->lchild);
		n=LeafCount(T->rchild);
		return m+n;
	}
	return 0;  //²¹³äÍê¸Ã²Ù×÷ºó£¬ÇëĞŞ¸Ä´ËĞĞ´úÂë
}


int a1=0,a2;
//Çó¶ş²æÊ÷TÖĞ¶ÈÎª1µÄ½áµã×ÜÊı
void NodeCount1(BiTree T) {
	//ÇëÍ¬Ñ§ÃÇ²¹³ä´Ë²Ù×÷
	if(T) {
		if((T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)) {
			a1++;
		}
		NodeCount1(T->lchild);
		NodeCount1(T->rchild);
	}
}

//Çó¶ş²æÊ÷TÖĞ¶ÈÎª2µÄ½áµã×ÜÊı
void NodeCount2(BiTree T) {
	if(T) {
		if(T->lchild!=NULL&&T->rchild!=NULL) {
			a2++;
		}
		NodeCount2(T->lchild);
		NodeCount2(T->rchild);
	}
}

int main() {
	BiTree T,p=NULL;       //TÎª±¾³ÌĞòÖĞÒª²Ù×÷µÄ¶ş²æÁ´±í
	char ch;    //ch±íÊ¾ÔÚ¶ş²æÊ÷ÖĞÒª²éÑ¯µÄ½áµã
	cout<<"ÇëÊäÈëÒª´´½¨µÄ¶ş²æÊ÷£¬°´ÏÈĞòĞòÁĞÊäÈë£¬¿ÕÊ÷ÓÃ×Ö·û'#'´úÌæ"<<endl;
	CreatBitree(T);  //¸ù¾İÊäÈëµÄ¶ş²æÊ÷ÏÈĞòĞòÁĞ£¬´´½¨¶ş²æÁ´±íT
	cout<<"ÇëÊäÈëÒª²éÑ¯µÄ½áµã"<<endl;
	cin>>ch;
	int n;
	level(T,ch,1,n);  //ÇóÖµÎªch½áµãµÄ²ãÊı£¬³õÊ¼Ê±¸ùµÄ²ãÊıÎª1
	cout<<"¸Ã½áµãµÄ²ã´ÎÎª"<<n<<endl;
	cout<<endl<<"ÖĞĞò±éÀú½á¹ûÎª£º"<<endl;
	InOrderTraverse(T);      //Êä³ö¶ş²æÊ÷TµÄÖĞĞò±éÀúĞòÁĞ
	cout<<endl<<"ÏÈĞò±éÀú½á¹ûÎª£º"<<endl;
	PreOrderTraverse(T);     //Êä³ö¶ş²æÊ÷TµÄÏÈĞò±éÀúĞòÁĞ
	cout<<endl<<"ºóĞò±éÀú½á¹ûÎª£º"<<endl;
	PostOrderTraverse(T);    //Êä³ö¶ş²æÊ÷TµÄºóĞò±éÀúĞòÁĞ
	cout<<endl<<"ÇëÊäÈëÔÚ¶ş²æÊ÷ÖĞÒª²éÕÒµÄ½áµã£º"<<endl;
	rewind(stdin);   //Çå¿ÕÊäÈë»º³åÇø
	cin>>ch;
	SearchTree(T,ch,p);   //ÔÚ¶ş²æÊ÷TÖĞ²éÕÒÖµÎªchµÄ½áµã
	if(flag)
		cout<<"ÔÚ¶ş²æÊ÷ÖĞ²éÕÒ³É¹¦,·µ»ØÖµÎª"<<p->data<<endl;
	else
		cout<<"¶ş²æÊ÷ÖĞ²»´æÔÚÖµÎª"<<ch<<"µÄ½áµã"<<endl;

	cout<<"¶ş²æÊ÷µÄÉî¶ÈÎª"<<Depth(T)<<endl;
	cout<<"¶ş²æÊ÷ÖĞ×Ü½áµãÊıÎª"<<NodeCount(T)<<endl;
	NodeCount1(T);
	NodeCount2(T);
	cout<<"Ò¶×Ó½áµãÊı¡¢¶ÈÎª1½áµãÊı¡¢¶ÈÎª2½áµãÊı·Ö±ğÎª£º"<<LeafCount(T)<<","<<a1<<","<<a2<<endl;
	return 0;
}
