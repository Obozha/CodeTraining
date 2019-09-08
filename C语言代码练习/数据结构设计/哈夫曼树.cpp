#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ---- ���������Ĵ洢��ʾ ----- 
typedef struct{
	int weight;				  // ����Ȩֵ
	int parent,lchild,rchild; // ����˫�ס����ӡ��Һ��ӵ��±� 
}HTNode,*HuffmanTree;		  // ��̬��������洢��������

// ---- �����������Ĵ洢��ʾ ---- 
typedef char **HuffmanCode; // ��̬��������洢����������� 

void Select(HuffmanTree HT,int len,int &s1,int &s2){
	int i,min1=0x3f3f3f3f,min2=0x3f3f3f3f;// �ȸ������ֵ
	for(i=1;i<=len;i++){
		if(HT[i].weight<min1&&HT[i].parent==0){
			// ѡ������Ȩ����С��Ȩ�أ���û��˫�׽��
			// ��̨�㷨 
			min1=HT[i].weight;
			s1=i;
			// s1��¼��1С��λ�� 
		}
	}
	int temp=HT[s1].weight;
	HT[s1].weight=0x3f3f3f3f;
	// ��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
	for(i=1;i<=len;i++){
		if(HT[i].weight<min2&&HT[i].parent==0){
			min2=HT[i].weight;
			// ��̨�㷨Ȩ����С��Ȩ�أ���û��˫�׽�� 
			// ѡȡ���н�� 
			s2=i;
		}
	}
	HT[s1].weight=temp; // �ָ�ԭ����ֵ
	printf("s1λ�ã�%d��s1��ֵ��%d��s2��λ��%d��s2��ֵ��%d\n",s1,s2,HT[s1].weight,HT[s2].weight);
}

void TraverHiffmanTreeData(HuffmanTree HF,int n){
	int i;
	printf("���i	weight	parent	lchild	rchild\n");
	for(i=1;i<=n;i++){
		if(HF[i].weight<500){
			printf("%d	%d	%d	%d	%d\n",i,HF[i].weight,HF[i].parent,HF[i].lchild,HF[i].rchild);
		}else{
			printf("%d	-	%d	%d	%d\n",i,HF[i].parent,HF[i].lchild,HF[i].rchild);
		}
	}
} 

void CreateHuffmanTree(HuffmanTree &HT,int n){
	// ������������HT
	int i,m=2*n-1,s1,s2;
	// Ϊʲôm=2n-1 ��Ϊ��������û�ж�Ϊ1�Ľ�� 
	if(n<=1)
		return;
	HT=(HuffmanTree)malloc(sizeof(HTNode)*(m+1)); 
//	printf("%d",m+1); 
	// 0�ŵ�Ԫδ�ã�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ�����
	for(i=1;i<=m;i++){	// ��1~m�ŵ�Ԫ�е�˫�ף����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0 
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&HT[i].weight);
	}	
	printf("==============HF�ĳ�̬==============\n");
	TraverHiffmanTreeData(HT,15); 
	/*==================��ʼ����������=====================*/
	for(i=n+1;i<=m;i++){
		Select(HT,i-1,s1,s2);
		// ��HT[k](1<=K<=K-1)��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ��
		// ������������HT�е����s1��s2
		HT[s1].parent=i;
		HT[s2].parent=i;
		// �õ��½��i����ɭ����ɾ��s1��s2����s1��s2��˫�����0��Ϊi
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight; 
	}
}

// �㷨5.11 
// ����洢n���ַ�����ı����ռ�HC������Ϊn+1��������ʱ�洢ÿ���ַ�����Ķ�̬����ռ�cd��cd[n-1]��Ϊ'\0'
// ������n���ַ��ı��룬ѭ��n�Σ�ִ�����²�����
// ���ñ���start���ڼ�¼������cd�д�ŵ�λ�ã�start��ʼʱָ����󣬼����������λ��n-1;
// ���ñ���c���ڼ�¼��Ҷ�ӽ�����ϻ�����������������Ľ���±꣬c��ʼʱΪ��ǰ�������ַ����±�i��f���ڼ�¼i��˫���±� 
// ��Ҷ�ӽ�����ϻ���������㣬����ַ�i�ı��룬��fû�дﵽ�����ʱ��ѭ��ִ�����²��� 
 
void CreateHuffmanCode(HuffmanTree HF,HuffmanCode &HC,int n){
	// ��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
	int i,start,c,f;
	HC=(HuffmanCode)malloc(sizeof(char*)*(n+1));	// ����洢n���ַ�����ı����ռ� 
	char* cd=(char*)malloc(sizeof(char)*n); 			// ������ʱ���ÿ���ַ�����Ķ�̬����ռ�
	cd[n-1]='\0';
	for(i=1;i<=n;i++){									// ����ַ������������ 
		start=n-1;										// start��ʼʱָ����󣬼��������
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

// ���� 5 29 7 8 14 23 3 11 
int main(){
	HuffmanTree HF;
	HuffmanCode HC;
	CreateHuffmanTree(HF,8);
	printf("==============HF����̬==============\n");
	TraverHiffmanTreeData(HF,15);
	
	CreateHuffmanCode(HF,HC,8);
	TraverseHuffmanCode(HC,8);
	
} 
