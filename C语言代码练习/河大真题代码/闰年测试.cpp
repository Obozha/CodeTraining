#include<iostream>
using namespace std;

int main(){
	
	for(int i=2000;i<=2050;i++){
		if((i%4==0&&i%100!=0)||i%400==0){
			cout<<i<<"ÄêÊÇÈòÄê"<<endl;	
		}
	}
	
	
}
