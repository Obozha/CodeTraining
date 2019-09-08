#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

main(){
	int count;
	printf("请输入增加学号人数:");	       // 首先获取学号人数 
	scanf("%d",&count);
	
	int* p = malloc(sizeof(int)*count);   // 申请堆内存给指针 
	int i;
	for(i = 0;i < count;i++){ 			// 给指针对应的堆内存的地址来接收用户输入的学号 
		printf("请输入每个人的学号");
		scanf("%d",p+i);
	}
	
	int newCount;  
	printf("请输入新增加学号的人数");
	scanf("%d",&newCount); // 获取新增加的学号人数 
	
	p = realloc(p,sizeof(int) * (count + newCount)); // 重新申请在堆内存的大小 
	
	for(i = count;i < count+newCount;i++){    // 然后再count位置下，一直到count+newCount位置下再次输入count个学号  
		printf("请输入每个人的学号");
		scanf("%d",p+i);
	}
	
	for(i = 0;i<count+newCount;i++){ // print 
		printf("第%d个同学的学号为%d\n",i+1,*(p+i));
	}
}
