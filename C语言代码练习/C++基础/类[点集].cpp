#include<iostream>
using namespace std;
class Point{
	private:
		double x,y;
	public:
		void set(double a,double b){
			x=a;
			y=b;
		}
		void show(){
			cout<<"x="<<x<<" y="<<y<<endl;
		}
};


int main(){
	Point a;// ������Ķ���
	a.set(3,9);
	a.show(); 
}
