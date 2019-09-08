#include<stdio.h>
#include<string.h>

// C语言提供了typedef您
// 可以使用它来为类型取一个新的名字。下面的实例为单字节数字定义了一个术语 BYTE：
// typedef unsigned char BYTE;
// BYTE  b1, b2;

typedef struct Books {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} Book;

int main() {
	Book book;

	strcpy(book.title,"C 教程");
	strcpy(book.author,"Runoob");
	strcpy(book.subject,"编程语言");

	book.book_id = 12345;
	printf("书标题：%s\n",book.title);
	printf("书作者：%s\n",book.author);
	printf("书类目：%s\n",book.subject);
	printf("书ID：%d\n",book.book_id);

	return 0;
}
