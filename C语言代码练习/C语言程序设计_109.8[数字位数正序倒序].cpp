#include<stdio.h>

int main(){
	int num=0;
	int a,b,c,d,e,n; /* 分别代表各位 十位 百位 千位 万位 和位数 */
	printf("请输入一个整数(0-99999)");
	scanf("%d",&num);
	
	if(num>99999&&num<0){
		return 0;
	}
	
	
	if(num>9999)
		n=5;
	else if(num>999)
		n=4;
	else if(num>99)
		n=3;
	else if(num>9)
		n=2;
	else
		n=1;
	printf("这是一个%d位的整数\n",n);
	printf("每位数字为:");
	
	e=num/10000;
	d=((num-e*10000)/1000);
	c=((num-e*10000-d*1000)/100);
	b=((num-e*10000-d*1000-c*100)/10);
	a=(num-e*10000-d*1000-c*100-b*10);
	
	switch(n) {
		case 5:
			printf("%d,%d,%d,%d,%d\n",e,d,c,b,a);
			printf("反转数字为:");
			printf("%d,%d,%d,%d,%d\n",a,b,c,d,e);
		break;
		case 4:
			printf("%d,%d,%d,%d\n",d,c,b,a);
			printf("反转数字为:");
			printf("%d,%d,%d,%d\n",a,b,c,d);
		break;
		case 3:
			printf("%d,%d,%d\n",c,b,a);
			printf("反转数字为:");
			printf("%d,%d,%d\n",a,b,c);
			break;
		case 2:
			printf("%d,%d\n",b,a);
			printf("反转数字为:");
			printf("%d,%d\n",a,b);
			break;
		case 1:
			printf("%d\n",a);
			break;
	}

}
 
