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
	cout<<"i��ֵ��:"<<i<<endl;
	cout<<"sum��ֵ�ǣ�"<<sum<<endl; 
} 
