#include<iostream>
#include"point.h"
using namespace std;

int main(){
	Point p;
	double x,y;
	for(;;){ // 重复输入x和y轴分量，直到x分量值小于0 
		cout<<"Enter x and y:\n";
		cin>>x>>y;
		if(x<0)
			break;
		p.Set(x,y);
		cout<<"angle="<<p.angle()
			<<",radius="<<p.radius()
			<<",x offset="<<p.xOffset()
			<<",y offset="<<p.yOffset()<<endl;
	}
	return 0;
}
