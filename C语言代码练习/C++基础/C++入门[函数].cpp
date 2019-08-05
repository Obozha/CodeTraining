#include<iostream> 
#include<math.h>
using namespace std;

int main(){
	double a,b,c;
	cout<<"input two numbers:"<<endl;
	cin>>a>>b;
	c=max(a,b);
	cout<<"the squart of maximum="<<sqrt(c);
	return 0;
}

double max(double x,double y){
	if(x>y)
		return x;
	else
		return y;
}
