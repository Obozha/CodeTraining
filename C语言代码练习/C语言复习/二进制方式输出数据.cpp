#include<stdio.h>
#define SIZE 10
struct Student_type{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[SIZE];

void save(){ // ���庯��save�����ļ����SIZE��ѧ�������� 
	FILE *fp;
	int i;
	if((fp=fopen("stu.dat","wb"))==NULL){	// �������ļ�stu.dat 
		printf("cannot open file\n");
		return;
	}
	for(i=0;i<SIZE;i++)
		if(fwrite(&stud[i],sizeof(struct Student_type),1,fp)!=1)
			printf("file write error\n");
	fclose(fp);
	
}

int main(){
	int i;
	printf("please enter data of students:\n");
	for(i=0;i<SIZE;i++)
		// ����SIZE��ѧ�������ݣ����������stud��
		scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
	save(); 
	return 0;
}
