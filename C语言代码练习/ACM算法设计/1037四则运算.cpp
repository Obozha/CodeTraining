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
				//����Ϊ���жϸ�������ȣ����ڼ��������ĸ�������2���Ƶģ��ھ�������һ����ƫ�if (disc == 0.0) ʱ��disc��һ����ȷ�ص���0��Ҳ������0.000001��Ϊ�˱��⸡�����Ƚ��ϵ�����Ҫ�趨һ����Χ��Ҳ����(-1e-6, 1e-6)�����Χ�ڣ����disc���������Χ�ڣ�����Ϊ�����0�ˡ� 
				
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
