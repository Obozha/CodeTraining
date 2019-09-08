#include<iostream>
using namespace std;

class Student{
	private:
		int m;
	public:
		Student(int m){
			cout<<m<<endl;;
			this->m=m;
		}
		void Show(){
			cout<<m<<endl;
		}
};

int main(){
//	Student* s=new Student(15);
	Student a(10);
	Student b(a); 
	Student c=a;
	a.Show();
	b.Show();
	c.Show();
	Student *ap=&a;
	Student *bp=&b;
	cout<<ap<<" "<<bp<<endl;
}
