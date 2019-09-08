#include<stdio.h>
#define N 3
struct Student{		 // 建立结构体类型struct Student 
	int num;	// 学号
	char name[20];	// 姓名
	float score[3];		// 3门课成绩
	float aver;		// 平均成绩 
}; 

void input(struct Student stu[]);
void print(struct Student stud); 
struct Student max(struct Student *stu);

int main(){
	struct Student stu[N];
	input(stu);
	print(max(stu)); 
	return 0;
}

void input(struct Student stu[]){	// 定义Input函数 
	int i;
	printf("请输入各学生的信息：学号、姓名、三门课成绩\n");
	for(i=0;i<N;i++){
		scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
		// 求平均成绩 
	}
}

struct Student max(struct Student* stu){
	int i,m=0;	
	for(i=0;i<N;i++){
		if(stu[i].aver>stu[m].aver)
			m=i;	
	}
	return stu[m];  
}

void print(struct Student stud){
	printf("\n成绩最高的学生是:\n");
	printf("学号：%d\n姓名：%s\n三门课成绩：%5.1f%5.1f%5.1f\n平均成绩：%6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}
