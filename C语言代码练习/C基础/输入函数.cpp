#include<stdio.h>
#include<stdlib.h>

main(){
	printf("������༶����\n");
	int number;
	// &:ȡ��number���ڴ��ַ
	scanf("%d",&number); 
	
	printf("������༶����:\n");
	char name[3];
	scanf("%s",&name);
	
	printf("�༶����Ϊ%d,�༶����Ϊ%s\n",number,name);
	
	printf("number���ڴ��ַ%#x\n",number);
	printf("name���ڴ��ַ%#x\n",name);
	system("pause");
}

