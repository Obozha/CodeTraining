#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void fn1();
void fn2();
extern int n; // 外部变量a的实际定义处 
int main(int argc, char** argv) {
	n=3;
	fn1(); // fn1()函数的定义在本文件中 
	cout<<n<<endl;
	return 0;
}

void fn1(){
	fn2(); // fn2()函数的定义不在本文件中 
}
