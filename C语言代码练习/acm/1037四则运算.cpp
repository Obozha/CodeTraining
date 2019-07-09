#include<stdio.h>
#include<math.h>

int main() {
	double a,b,ans;
	char c;
	int flag=0;
	scanf("%lf %c %lf",&a,&c,&b);

	switch(c) {
		case '+':
			ans=a+b;
			break;
		case '-':
			ans=a-b;
			break;
		case '*':
			ans=a*b;
			break;
		case '/':
			if(fabs(b)<1e-10)
				//这是为了判断浮点数相等，由于计算机保存的浮点数是2进制的，在精度上有一定的偏差。if (disc == 0.0) 时，disc不一定精确地等于0，也许会等于0.000001。为了避免浮点数比较上的误差，就要设定一个误差范围，也就是(-1e-6, 1e-6)这个范围内，如果disc落在这个范围内，就认为其等于0了。 
				
				flag=1;
			else
				ans=a/b;
			break; 
		default:flag=1;
	}
	
	if(flag==0){
		printf("%.2lf", ans);
	}else{
		printf("Wrong input!");
	}
}
