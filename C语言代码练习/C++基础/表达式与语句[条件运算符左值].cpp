#include<iostream> 
#include<math.h>
using namespace std;

int main(){
	// ��һ������������ı��ʽ�У��������������ʽֵ������ͬ����Ϊ��ֵ
	// ���������������ʽ��ֵΪ��ֵ���ʽ 
	int x=5;
	long a,b;
	(x?a:b)=1; // ok ��Ϊ���Ҷ�����ֵ
	//(x?x:a)=2; // error x��a����һ�����͡� �������������Ϊ(long)x��a 
	//(x==a?1:a)=3; // error:1��������ֵ 
	cout<<a;
}
