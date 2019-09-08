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
	// 第二个字符串将覆盖掉第一个字符串的所有内容！ 
	// 注意:在定义数组时，字符数组1的字符串长度必须大于或等于字符串2长度。
	// 
	
	char a[] = "hello 123";
    fuc(a);
//    const char b[] = "hello 123";
//    fuc(b);
}

