#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void fn1();
void fn2();
extern int n; // �ⲿ����a��ʵ�ʶ��崦 
int main(int argc, char** argv) {
	n=3;
	fn1(); // fn1()�����Ķ����ڱ��ļ��� 
	cout<<n<<endl;
	return 0;
}

void fn1(){
	fn2(); // fn2()�����Ķ��岻�ڱ��ļ��� 
}
