#include<stdio.h>
#include<string.h>


int main() {
	void sort(char *name[],int n);
	void print(char *name[],int n);
	char *name[]= {"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
	// char *一共四个指针 分别指向 四个常量


	int n=5;
	sort(name,n); // 调用sort函数，对字符串排序
	print(name,n); // 调用print 函数，输出字符串
	return 0;
}

/**
	strcmp 比较两个字符
	str1<str2，返回负数
	str1=str2，返回0
	str1>str2，返回正数
*/

// deprecated conversion from string constant to 'char*' [-Wwrite-strings]
// 不赞成的    转换      从 string 常量 到 字符指针
// name在改变的时候换了指向


void sort(char *name[],int n) { 	// 定义sort函数
	char *temp;
	int i,j,k;
	for(i=0; i<n-1; i++) { // i趟数，设置成n-1 0~n-2一共 n-1次
		k=i; // 设置最小坐标
		for(j=i+1; j<n; j++)  // 通过比较获得最小值坐标
			if(strcmp(name[k],name[j])>0) // name[k] >name[j]
				k=j;
		if(k!=i) {
			temp=name[i];
			name[i]=name[k];
			name[k]=temp;
		}
	}
}

//void print(char *name[],int n) { // 定义print函数   char *name[] -> 指向指针数组的函数
//	int i;
//	for(i=0; i<n; i++) {
//		printf("%s\n",name[i]); // 按指针数组元素的顺序输出它们所指向的字符串
//	}
//}

void print(char *name[],int n) {
	int i=0;
	char *p;
	p=name[0];
	while(i<n) {
		//[Error] cannot convert 'char**' to 'char*' in assignment 
		// 这里的解释的意思是
		// name+i++ 为数组指针的指针/地址
		// *(name) -> 取地址 
		printf("%s\n",*(name+i));
		i++;
	}
}

