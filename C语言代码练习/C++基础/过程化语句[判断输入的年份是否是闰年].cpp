#include<iostream>
using namespace std;

int main() {
	unsigned nYear;
	while(1) {
		cout<<"���������";
		cin>>nYear;
		// (!(nYear%400)||(!(nYear%4)&&(nYear%100)));
		if((nYear%400==0)||(nYear%4==0)&&(nYear%100!=0))
			cout<<nYear<<"������!"<<endl;
		else
			cout<<nYear<<"��������!"<<endl;
	}

}
