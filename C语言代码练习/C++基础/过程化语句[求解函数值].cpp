#include<iostream>
using namespace std;

int main() {
	int x,y;
	cout<<"������һ������:";
	while(1) {
		cin>>x;
		if(x>0)
			y=1;
		else if(x==0)
			y=0;
		else
			y=-1;
		cout<<"y="<<y<<endl;
	}
	return 0;
}
