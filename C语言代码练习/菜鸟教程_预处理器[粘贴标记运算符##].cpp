#include<stdio.h> 

#define tokenpaster(n) printf("token"#n" = %d",token##n)
// 宏定义的标记粘贴运算符(##)会合并两个参数，它允许在宏定义中两个独立的标记被合并为一个标记
 

int main(){
	int token34 = 40;
	tokenpaster(34);
	return 0;
}
