#include<stdio.h>

int main(){
	void print_star();  
	void print_message();
	// 声明函数 
	
	print_star();
	print_message();
	print_star();
	// 调用函数 
} 

void print_star(){
	printf("*****************\n");
} 

void print_message(){
	printf("How do you do\n"); 
}
