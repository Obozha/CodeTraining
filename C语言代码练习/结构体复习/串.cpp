#include<stdio.h>
#include<string.h>

#define MAXLEN 255 // ������󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct{
	char ch[MAXLEN+1];  // ��Ŵ����ַ����飬0�ŵ�Ԫ���� 
	int length;			// ���ĵ�ǰ���� 
}SString; 
// C�����У�'\0'Ϊ���Ľ����� 

// ���⣺�������Ĵ洢�ռ��ڳ���ִ�й����ж�̬���� 

void Concat(SString &T,SString S1,SString S2){
	// ��T������S1��S2������ɵ��´�
	int j=1,k=1; 
	while(j<=S1.length)
		T.ch[k++]=S1.ch[j++]; // ���ƴ�S1
	while(j<=S2.length)
		T.ch[k++]=S2.ch[j++]; // ���ƴ�S2
	T.ch[k]='\0';
	T.length=S1.length+S2.length; 
} // Concat

Status StrAssign(SString &T,const char *chars){ // ����һ����ֵ����chars�Ĵ�T 
	int i;
	if(strlen(chars)>MAXLEN)
		return ERROR;
	else{
		T.ch[0]=strlen(chars);
		for(i=1;i<=T.ch[0];i++)
			T.ch[i]=*(chars+i-1); // chars��0��ʼ��T��1��ʼ 
		return OK;
	}
}

void strinsert(SString &S,int i,SString T){
	int k;
	if(i<1||i>S.length+1||S.length+T.length>MAXLEN){
		// �Ƿ��������
		printf("cannot insert\n"); 
	}else{
		for(k=S.length;k>=i;k--){
			S.ch[T.length+k]=S.ch[k]; 
		} // S�дӵ�i��Ԫ�ؿ�ʼ����
		for(k=1;k<=T.length;k++)
			S.ch[i+k-1]=T.ch[k];
		S.length=S.length+T.length;
		S.ch[S.length+1]='\0'; 
	}
}

int Index_BF(SString S,SString T,int pos){
	int i=pos,j=1;
	while(i<=S.ch[0]&&j<=T.ch[0]){
		if(S.ch[i]==T.ch[j]){
			i++;
			j++;			// �����ȽϺ���ַ� 
		}else{
			i=i-j+2;		// ָ��������¿�ʼƥ�� 
			j=1;
		}
	}
	if(j>T.ch[0])
		return i-T.ch[0];
		else return 0;
}

void get_next(SString T,int* next){
	// ��ģʽ��T��next����ֵ����������
	int i=1;		// ��Ϊ0��λ�ô�ŵ���ģʽ���Ĵ�С 
	next[1]=0;
	int j=0;
	while(i<T.ch[0]){
		if(j==0||T.ch[i]==T.ch[j]){
			i++;
			j++;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
}

void get_nextval(SString T,int nextval[]){
	// ��ģʽ����next��������ֵ����������nextval 
} 

int Index_KMP(SString S,SString T,int pos,int next[]){
	// ����ģʽ��T��next������T�������е�pos���ַ�֮���λ��
	// ���У�T�ǿգ�1<pos<S.length
	int i=pos,j=1;
	while(i<=S.ch[0]&&j<=T.ch[0]){ // ��������Ϊ�Ƚϵ�ĩβ 
		if(j==0||S.ch[i]==T.ch[j]){	// �����ȽϺ����ַ� 
			i++;
			j++;
		}else{
			j=next[j]; 
		}
	}
	if(j>T.ch[0])
		return i-T.ch[0]; // ƥ��ɹ�
	else 
		return 0;
} 

int main(){
	SString S;
	StrAssign(S,"acabaabaabcacaabc");
	SString T;
	StrAssign(T,"abaabcac");
	
	int next[T.ch[0]];
	int i;
	
	get_next(T,next);
	for(i=1;i<=T.ch[0];i++){
		printf("%d ",next[i]);
	}
	
	int b=Index_KMP(S,T,1,next);
	
	
	int a=Index_BF(S,T,1);
	printf("BF��λ����%d\nKMP��λ����%d\n",a,b);
}
