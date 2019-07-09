#include<stdio.h>
#include<string.h>

int main(){
	struct Student{ 
		long num;
		char name[20];
		char sex;
		float score;
	};
	
	struct Student stu_1; // 定义struct Student类型的变量stu_1
	struct Student *p; // 定义指向struct Student类型数据的指针变量p
	p=&stu_1;  // p指向stu_1
	stu_1.num=10101;
	strcpy(stu_1.name,"Li Lin"); //用字符串复制函数给stu1.name赋值
	stu_1.sex='M';
	stu_1.score=89.5;
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n",stu_1.num,stu_1.name,stu_1.sex,stu_1.score);
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n",(*p).num,(*p).name,(*p).sex,(*p).score);
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n",p->num,p->name,p->sex,p->score);

}
