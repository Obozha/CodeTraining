#include<stdio.h>
#define N 3
struct Student{		 // �����ṹ������struct Student 
	int num;	// ѧ��
	char name[20];	// ����
	float score[3];		// 3�ſγɼ�
	float aver;		// ƽ���ɼ� 
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

void input(struct Student stu[]){	// ����Input���� 
	int i;
	printf("�������ѧ������Ϣ��ѧ�š����������ſγɼ�\n");
	for(i=0;i<N;i++){
		scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
		// ��ƽ���ɼ� 
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
	printf("\n�ɼ���ߵ�ѧ����:\n");
	printf("ѧ�ţ�%d\n������%s\n���ſγɼ���%5.1f%5.1f%5.1f\nƽ���ɼ���%6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}
