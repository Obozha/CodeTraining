#include<stdio.h>
#include<string.h>

struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
}; 

/* 函数声明 */
void printBook(struct Books book);

int main(){
	struct Books book1; /* 声明book1,类型为Books */
	struct Books book2; /* 声明book2,类型为Books */
	
	/* Book1详述 */
	strcpy(book1.title,"C programming");
	strcpy(book1.author,"Nuha Ali");
	strcpy(book1.subject,"C programing Tutorial");
	book1.book_id = 6495407;
	
	strcpy(book2.title,"Telecom Billing");
	strcpy(book2.author,"Zara Ali");
	strcpy(book2.subject,"Telecom Billing Tutorial");
	book2.book_id = 6496700;
	
	printBook(book1);
	printBook(book2);
	return 0;
}

void printBook(struct Books book){
	printf("Book title:%s\n",book.title);
	printf("Book author:%s\n",book.author);
	printf("Book subject:%s\n",book.subject);
	printf("Book book_id:%d\n",book.book_id);
}
