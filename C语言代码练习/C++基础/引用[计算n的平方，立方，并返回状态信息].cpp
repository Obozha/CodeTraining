#include<iostream> 
using namespace std;
int Factor(int,int&,int&);

int main(){
	int number,squared,cubed,error;
	cout<<"Enter a number(0-20):";
	cin>>number;
	error=Factor(number,squared,cubed);
	if(error)
		cout<<"Error encounter!"<<endl;
	else{
		cout<<"Number:"<<number<<endl;
		cout<<"Squared:"<<squared<<endl;
		cout<<"Cubed:"<<cubed<<endl;
	}
	return 0;
}

int Factor(int n,int& rSquared,int& rCubed){
	if(n>20||n<0)
		return 1;
	rSquared=n*n;
	rCubed=n*n*n;
	return 0;
}
