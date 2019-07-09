// struct Books *struct_pointer;  ����ָ��ṹ��ָ�� 
// struct_pointer = &Book1;        
// struct_pointer->title          ָ��ýṹ��ָ����ʽṹ�ĳ�Ա

#include<stdio.h>
#include<string.h>

struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
}; 

/* �������� */
void printBook(struct Books* book);
 
int main(){
	struct Books book1; /* ����book1,����Ϊ Books */
	struct Books book2; /* ����book2,����Ϊ Books */
	
	/* Book1 ���� */
	strcpy(book1.title,"C programming");
	strcpy(book1.author,"Nuha Ali");
	strcpy(book1.subject,"C Programming Tutorial");
	book1.book_id = 6495407;
	
	/* Book2 ���� */
	strcpy(book2.title,"Telecom Billing");
	strcpy(book2.author,"Zara Ali");
	strcpy(book2.subject,"Telecom Billing Tutorial");
	book2.book_id = 6495700;
	
	printBook(&book1);
	printBook(&book2);
	return 0;
	
}

// [Error] could not convert '& book1' from 'Books*' to 'Books'
// ��������  


void printBook(struct Books *book){
	printf("Book title:%s\n",book->title);
	printf("Book author:%s\n",book->author);
	printf("Book subject:%s\n",book->subject);
	printf("Book book_id:%d\n",book->book_id); 
}
