#include<stdio.h>

int fun(int,int,int(*p)(int,int));
int max(int,int);
int min(int,int);
int add(int,int);

int main(){
	int a=34,b=-21,n;
	printf("please choose 1,2 or 3:");
	scanf("%d",&n); // ����1 2 3 
	if(n==1)
		fun(a,b,max); // ����1��max 
	else if(n==2)
		fun(a,b,min); // ����2��min 
	else if(n==3)
		fun(a,b,add); // ����3��add
	return 0; 
}

int fun(int x,int y,int (*p)(int,int)){ // ����fun���� 
	int result;
	result=(*p)(x,y); 
	printf("%d\n",result); // ������ 
}

int max(int x,int y){
	int z;
	if(x>y)
		z=x;
	else
		z=y;
	return z;
}

int min(int x,int y){
	int z;
	if(x<y)
		z=x;
	else
		z=y;
	return z;
}

int add(int x,int y){
	int z;
	z=x+y;
	printf("sum=");
	return z;
}
