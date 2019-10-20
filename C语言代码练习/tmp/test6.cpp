#include<iostream>
using namespace std;
int main(){
	int i=1,sum=0;
	while(i<=100){
		sum+=i;
		i++;
	}
	cout<<sum<<endl;

	sum=0;
	for(i=1;i<=100;i++){
		sum+=i;
	}
	cout<<sum<<endl;

	sum=0;
	i=1;
	do{
		sum+=i;
		i++;
	}while(i<=100);
	cout<<sum<<endl;
} 
