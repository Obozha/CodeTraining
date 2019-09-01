#include<iostream>
using namespace std;
int main(){
	int x=100;
	int &xx=x;
	int y=999;
	int &yy=y;
	cout<<x<<" "<<xx<<endl;
	cout<<&x<<" "<<&xx<<endl;
	cout<<y<<" "<<yy<<endl;
	cout<<&y<<" "<<&yy<<endl;
	return 0;
}
