#include<stdio.h>
#include<string.h> 


int fuc( char *a){
	printf("%s",a);
}

//int fuc(const char *a){
//	printf("%s",a);
//}

int main(){
//	const char *a="hello"; 
//	char *b="world"	;
// 	strcpy(a,b);

//	char str1[10]={"hfdaffaOk"};
//	char str2[10]={"Compudter"};
//	strcpy(str1,str2); 
//	printf("%s",str1);
	// �ڶ����ַ��������ǵ���һ���ַ������������ݣ� 
	// ע��:�ڶ�������ʱ���ַ�����1���ַ������ȱ�����ڻ�����ַ���2���ȡ�
	// 
	
	char a[] = "hello 123";
    fuc(a);
//    const char b[] = "hello 123";
//    fuc(b);
}

