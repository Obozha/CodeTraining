#include<stdio.h> 

#define tokenpaster(n) printf("token"#n" = %d",token##n)
// �궨��ı��ճ�������(##)��ϲ������������������ں궨�������������ı�Ǳ��ϲ�Ϊһ�����
 

int main(){
	int token34 = 40;
	tokenpaster(34);
	return 0;
}
