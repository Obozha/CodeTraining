#include<stdio.h>
#include<string.h>

#define MAXLEN 255 // 串的最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct{
	char ch[MAXLEN+1];  // 存放串的字符数组，0号单元不用 
	int length;			// 串的当前长度 
}SString; 
// C语言中，'\0'为串的结束符 

// 特殊：串变量的存储空间在程序执行过程中动态分配 

void Concat(SString &T,SString S1,SString S2){
	// 以T返回由S1和S2联结而成的新串
	int j=1,k=1; 
	while(j<=S1.length)
		T.ch[k++]=S1.ch[j++]; // 复制串S1
	while(j<=S2.length)
		T.ch[k++]=S2.ch[j++]; // 复制串S2
	T.ch[k]='\0';
	T.length=S1.length+S2.length; 
} // Concat

Status StrAssign(SString &T,const char *chars){ // 生成一个其值等于chars的串T 
	int i;
	if(strlen(chars)>MAXLEN)
		return ERROR;
	else{
		T.ch[0]=strlen(chars);
		for(i=1;i<=T.ch[0];i++)
			T.ch[i]=*(chars+i-1); // chars从0开始，T从1开始 
		return OK;
	}
}

void strinsert(SString &S,int i,SString T){
	int k;
	if(i<1||i>S.length+1||S.length+T.length>MAXLEN){
		// 非法情况处理
		printf("cannot insert\n"); 
	}else{
		for(k=S.length;k>=i;k--){
			S.ch[T.length+k]=S.ch[k]; 
		} // S中从第i个元素开始后移
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
			j++;			// 继续比较后继字符 
		}else{
			i=i-j+2;		// 指针后退重新开始匹配 
			j=1;
		}
	}
	if(j>T.ch[0])
		return i-T.ch[0];
		else return 0;
}

void get_next(SString T,int* next){
	// 求模式串T的next函数值并存入数组
	int i=1;		// 因为0的位置存放的是模式串的大小 
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
	// 求模式串的next函数修正值并存入数组nextval 
} 

int Index_KMP(SString S,SString T,int pos,int next[]){
	// 利用模式串T的next函数求T在主串中第pos个字符之后的位置
	// 其中，T非空，1<pos<S.length
	int i=pos,j=1;
	while(i<=S.ch[0]&&j<=T.ch[0]){ // 两个串均为比较到末尾 
		if(j==0||S.ch[i]==T.ch[j]){	// 继续比较后续字符 
			i++;
			j++;
		}else{
			j=next[j]; 
		}
	}
	if(j>T.ch[0])
		return i-T.ch[0]; // 匹配成功
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
	printf("BF的位置是%d\nKMP的位置是%d\n",a,b);
}
