#include<iostream>
using namespace std;

class Point {
		double x,y;
	public:
		Point(int x);
		void show() {
			cout<<x<<" "<<y;
		}
};

Point::Point(int x) {
	if(x==0){
		return;
	}else{
		cout<<x;
	}
}

int main() {
//	Point p(3,4);
//	p.show();
	
	Point p(0);
	
}
