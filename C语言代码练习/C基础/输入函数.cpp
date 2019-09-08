#include<stdio.h>
#include<stdlib.h>

main(){
	printf("请输入班级人数\n");
	int number;
	// &:取出number的内存地址
	scanf("%d",&number); 
	
	printf("请输入班级名称:\n");
	char name[3];
	scanf("%s",&name);
	
	printf("班级人数为%d,班级名称为%s\n",number,name);
	
	printf("number的内存地址%#x\n",number);
	printf("name的内存地址%#x\n",name);
	system("pause");
}

