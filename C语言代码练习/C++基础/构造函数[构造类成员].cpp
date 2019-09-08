#include<iostream>
using namespace std;

class SillyClass{
	public:
		SillyClass(int &i):ten(10),refI(i){
			
		} 
	protected:
		const int ten; // 常量数据成员  必须使用冒号语法初始化常量和引用 
		int &refI; 	   // 引用数据成员 
};

int main(){
	int i;
	SillyClass sc(i);
	int c(10); 
}
