#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ---- 哈夫曼树的存储表示 ----- 
typedef struct{
	int weight;				  // 结点的权值
	int parent,lchild,rchild; // 结点的双亲、左孩子、右孩子的下标 
}HTNode,*HuffmanTree;		  // 动态分配数组存储哈夫曼树

// ---- 哈夫曼编码表的存储表示 ---- 
typedef char **HuffmanCode; // 动态分配数组存储哈夫曼编码表 

void Select(HuffmanTree HT,int len,int &s1,int &s2){
	int i,min1=0x3f3f3f3f,min2=0x3f3f3f3f;// 先赋予最大值
	for(i=1;i<=len;i++){
		if(HT[i].weight<min1&&HT[i].parent==0){
			// 选出所有权重最小的权重，且没有双亲结点
			// 擂台算法 
			min1=HT[i].weight;
			s1=i;
			// s1纪录第1小的位置 
		}
	}
	int temp=HT[s1].weight;
	HT[s1].weight=0x3f3f3f3f;
	// 将原值存放起来，然后先赋予最大值，防止s1被重复选择
	for(i=1;i<=len;i++){
		if(HT[i].weight<min2&&HT[i].parent==0){
			min2=HT[i].weight;
			// 擂台算法权重最小的权重，且没有双亲结点 
			// 选取所有结点 
			s2=i;
		}
	}
	HT[s1].weight=temp; // 恢复原来的值
	printf("s1位置：%d，s1的值：%d，s2的位置%d，s2的值：%d\n",s1,s2,HT[s1].weight,HT[s2].weight);
}

void TraverHiffmanTreeData(HuffmanTree HF,int n){
	int i;
	printf("结点i	weight	parent	lchild	rchild\n");
	for(i=1;i<=n;i++){
		if(HF[i].weight<500){
			printf("%d	%d	%d	%d	%d\n",i,HF[i].weight,HF[i].parent,HF[i].lchild,HF[i].rchild);
		}else{
			printf("%d	-	%d	%d	%d\n",i,HF[i].parent,HF[i].lchild,HF[i].rchild);
		}
	}
} 

void CreateHuffmanTree(HuffmanTree &HT,int n){
	// 构建哈夫曼树HT
	int i,m=2*n-1,s1,s2;
	// 为什么m=2n-1 因为哈夫曼树没有度为1的结点 
	if(n<=1)
		return;
	HT=(HuffmanTree)malloc(sizeof(HTNode)*(m+1)); 
//	printf("%d",m+1); 
	// 0号单元未用，所以需要动态分配m+1个单元，HT[m]表示根结点
	for(i=1;i<=m;i++){	// 将1~m号单元中的双亲，左孩子，右孩子的下标都初始化为0 
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&HT[i].weight);
	}	
	printf("==============HF的初态==============\n");
	TraverHiffmanTreeData(HT,15); 
	/*==================初始化工作结束=====================*/
	for(i=n+1;i<=m;i++){
		Select(HT,i-1,s1,s2);
		// 在HT[k](1<=K<=K-1)中选择两个其双亲域为0且权值最小的结点
		// 并返回它们在HT中的序号s1和s2
		HT[s1].parent=i;
		HT[s2].parent=i;
		// 得到新结点i，从森林中删除s1，s2，将s1和s2的双区域从0改为i
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight; 
	}
}

// 算法5.11 
// 分配存储n个字符编码的编码表空间HC，长度为n+1；分配临时存储每个字符编码的动态数组空间cd，cd[n-1]置为'\0'
// 逐个求解n个字符的编码，循环n次，执行以下操作：
// 设置变量start用于纪录编码在cd中存放的位置，start初始时指向最后，即编码结束符位置n-1;
// 设置变量c用于纪录从叶子结点向上回溯至根结点所经过的结点下标，c初始时为当前待编码字符的下标i，f用于纪录i的双亲下标 
// 从叶子结点向上回溯至根结点，求得字符i的编码，当f没有达到根结点时，循环执行以下操作 
 
void CreateHuffmanCode(HuffmanTree HF,HuffmanCode &HC,int n){
	// 从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
	int i,start,c,f;
	HC=(HuffmanCode)malloc(sizeof(char*)*(n+1));	// 分配存储n个字符编码的编码表空间 
	char* cd=(char*)malloc(sizeof(char)*n); 			// 分配临时存放每个字符编码的动态数组空间
	cd[n-1]='\0';
	for(i=1;i<=n;i++){									// 逐个字符求哈夫曼编码 
		start=n-1;										// start开始时指向最后，即编码结束
		c=i;
		f=HF[i].parent;
		while(f!=0){
			start--;
			if(HF[f].lchild==c)
				cd[start]='0';
			else 
				cd[start]='1';
			c=f;
			f=HF[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
} 

void TraverseHuffmanCode(HuffmanCode HC,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("%s\n",HC[i]); 
	}
}

// 数据 5 29 7 8 14 23 3 11 
int main(){
	HuffmanTree HF;
	HuffmanCode HC;
	CreateHuffmanTree(HF,8);
	printf("==============HF的终态==============\n");
	TraverHiffmanTreeData(HF,15);
	
	CreateHuffmanCode(HF,HC,8);
	TraverseHuffmanCode(HC,8);
	
} 
