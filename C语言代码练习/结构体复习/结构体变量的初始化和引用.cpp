#include<stdio.h>

int main(){
	struct Student{ // �����ṹ������struct Student 
		long int num;  // ����4��Ϊ�ṹ���Ա 
		char name[20];
		char sex;
		char addr[20];
	}a={10101,"Li Lin",'M',"123 Beijing Road"}; // ����ṹ�����a����ʼ��
	printf("NO.:%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr); 
}
