#include<stdio.h>  
#include<stdlib.h>

void study(){
	printf("�Է�˯���򶹶�\n");
}

struct student{
	int age;
	int height;
	char sex;
	void (*studyP)(); // ���巽��ָ�� 
};


main(){
	struct student st = {31,175,'m',study};
	
	printf("%d\n",st.age);
	printf("%d\n",st.height);
	printf("%c\n",st.sex);
	
	st.studyP();
	// �ṹ��ĳ��Ȼ��Զ����룬Ϊ�˽���ָ������ 
	struct student * stp = &st;
	(*stp).studyP(); // ָ����ʽṹ��st˳������studyP()����; 
	stp->studyP();
	// ָ��ֱ�ӵ��� .�� 
}
