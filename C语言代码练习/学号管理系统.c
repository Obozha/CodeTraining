#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

main(){
	int count;
	printf("����������ѧ������:");	       // ���Ȼ�ȡѧ������ 
	scanf("%d",&count);
	
	int* p = malloc(sizeof(int)*count);   // ������ڴ��ָ�� 
	int i;
	for(i = 0;i < count;i++){ 			// ��ָ���Ӧ�Ķ��ڴ�ĵ�ַ�������û������ѧ�� 
		printf("������ÿ���˵�ѧ��");
		scanf("%d",p+i);
	}
	
	int newCount;  
	printf("������������ѧ�ŵ�����");
	scanf("%d",&newCount); // ��ȡ�����ӵ�ѧ������ 
	
	p = realloc(p,sizeof(int) * (count + newCount)); // ���������ڶ��ڴ�Ĵ�С 
	
	for(i = count;i < count+newCount;i++){    // Ȼ����countλ���£�һֱ��count+newCountλ�����ٴ�����count��ѧ��  
		printf("������ÿ���˵�ѧ��");
		scanf("%d",p+i);
	}
	
	for(i = 0;i<count+newCount;i++){ // print 
		printf("��%d��ͬѧ��ѧ��Ϊ%d\n",i+1,*(p+i));
	}
}
