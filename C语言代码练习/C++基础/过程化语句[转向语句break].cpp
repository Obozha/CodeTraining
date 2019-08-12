#include<iostream>
using namespace std;

int main(){
	int i=1,sum=0;
	while(i<=100){
		sum+=i;
		i++;
		if(i==15)
			break;
	}
	cout<<"i的值是:"<<i<<endl;
	cout<<"sum的值是："<<sum<<endl; 
} 
