#include<stdio.h>
#define N 3

struct Student{
	int num; // ѧ�� 
	char name[20]; // ���� 
	float score[3]; // 3�ſγɼ� 
	float aver; // ƽ���ɼ� 
};

void input(struct Student *stu);
void print(struct Student stud);
struct Student max(struct Student stu[]);

int main(){
	struct Student stu[N];
	input(stu);
	print(max(stu));
	return 0;
} 

struct Student max(struct Student stu[]){ // ����max���� 
	int i,m=0;
	for(i=0;i<N;i++){
		if(stu[i].aver>stu[m].aver)
			m=i;
	}
	return stu[m];
}

/**
	������Ϣ 
*/
void input(struct Student *stu){
	int i;
	printf("�������ѧ������Ϣ��ѧ�š����������ſεĳɼ���\n");
	struct Student *p;
	for(p=stu;p<stu+3;p++){
		scanf("%d %s %f %f %f",&(p->num),p->name,&(p->score[0]),&(p->score[1]),&(p->score[2]));
		p->aver=((p->score[0])+(p->score[1])+(p->score[2]))/3;
		// ��ƽ���ɼ� 
	}
}

void print(struct Student stud){ // ����print���� 
	printf("\n�ɼ���ߵ�ѧ���ǣ�\n");
	printf("ѧ�ã�%d\n������%s\n���ſγɼ���%5.1f,%5.1f,%5.1f\nƽ���ɼ���%6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);	
} 
