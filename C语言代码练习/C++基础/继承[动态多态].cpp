#include<iostream>
using namespace std;
 
class Student{
	public:
		double calcTuition(){
			cout<<"��ѧ��"<<endl;
		} // ѧ��ѧ�Ѽ��� 
};

class GraduateStudent:public Student{
	public:
		double calcTuition(){
			cout<<"8000"<<endl;
		}; 
	// ...
};

void fn(Student& x){ // �ɷѴ��� 
	x.calcTuition(); // ѧ�Ѽ��� 
}

int main(){
	Student ds;
	fn(ds); // ����ѧ��ѧ�� 
	GraduateStudent gs;
	fn(gs);	// �����о���ѧ�� 
}

// ˵�� ���������Ǹ�������������һ��ջ�
// ��Ϊ��������ԭ���ǽ��������ֱ���ͬ����������ɱ���������ĸ��� 
