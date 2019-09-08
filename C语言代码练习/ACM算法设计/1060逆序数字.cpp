#include<stdio.h>
// 整数n对10取模可得到个位上的数字
// 利用整数商是整数这一特点，整数n除以10的商正好“扔掉”了个位上的数字 
int main(){
	int n;
	scanf("%d",&n);	
	while(n>0){
		printf("%d ",n%10); // 输出个位
		n=n/10; 
	}
	return 0;
}
