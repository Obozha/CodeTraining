#include<stdio.h>

int main(){
	struct Student{ // �����ṹ������ struct Student 
		int num;
		char name[20];
		float score;
	}student1,student2; // ���������ṹ�����student1,student2
	
	scanf("%d%s%f",&student1.num,student1.name,&student1.score); // ����ѧ��1������
	scanf("%d%s%f",&student2.num,student2.name,&student2.score);	//����ѧ��2������
	
	printf("The higher score is:\n");
	if(student1.score>student2.score){
		printf("%d  %s  %6.2f\n",student1.num,student1.name,student1.score);
	}else if(student1.score<student2.score){
		printf("%d  %s  %6.2f\n",student2.num,student2.name,student2.score);
	}else{
		printf("%d  %s  %6.2f\n",student1.num,student1.name,student1.score);
		printf("%d  %s  %6.2f\n",student2.num,student2.name,student2.score);
	}
 
} 
