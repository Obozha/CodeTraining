#include<stdio.h> 

int max(int x,int y); // 函数声明 
int main(){
	int a[10],m,n,i;
	printf("enter 10 integer numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\n");
	for(i=0,m=a[0],n=0;i<10;i++){
		if(max(m,a[i])>m) { // 若max函数返回的值大于m 
		 	
			m=max(m,a[i]); // max返回的值取代m的原值 
			n=i;		   // 把此组元素的序号记下来 放在n中。 
		}
	}
	printf("The largest number is %d\n it is the %dth number. \n",m,n+1);
}

int max(int x,int y){ // 定义max函数 
	return (x>y?x:y); // 返回x和y的大者 
}
