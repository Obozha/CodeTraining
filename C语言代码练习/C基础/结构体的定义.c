#include<stdio.h>  
#include<stdlib.h>

void study(){
	printf("吃饭睡觉打豆豆\n");
}

struct student{
	int age;
	int height;
	char sex;
	void (*studyP)(); // 定义方法指针 
};


main(){
	struct student st = {31,175,'m',study};
	
	printf("%d\n",st.age);
	printf("%d\n",st.height);
	printf("%c\n",st.sex);
	
	st.studyP();
	// 结构体的长度会自动补齐，为了进行指针运算 
	struct student * stp = &st;
	(*stp).studyP(); // 指针访问结构体st顺带调用studyP()方法; 
	stp->studyP();
	// 指针直接调用 .。 
}
