#include<iostream>
using namespace std;
 
class Student{
	public:
		double calcTuition(){
			cout<<"交学费"<<endl;
		} // 学生学费计算 
};

class GraduateStudent:public Student{
	public:
		double calcTuition(){
			cout<<"8000"<<endl;
		}; 
	// ...
};

void fn(Student& x){ // 缴费处理 
	x.calcTuition(); // 学费计算 
}

int main(){
	Student ds;
	fn(ds); // 计算学生学费 
	GraduateStudent gs;
	fn(gs);	// 计算研究生学费 
}

// 说明 子类对象就是父类对象的性质是一句空话
// 因为操作起来原来是将子类对象粗暴的同化，根本扼杀了子类对象的个性 
