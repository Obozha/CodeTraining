#include<iostream>
using namespace std;

int main(){
	int a[]={1,1,2,2,2,3,4,5,5,5,6,6,6,6};
	int count=1;
	int maxNum=0;
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		while(a[i]==a[i+1]){
			count++;
			i++;
		}
		if(maxNum<count){
			maxNum=count;	
		}
		count=1; 
	} 
	cout<<maxNum;
} 
