#include<iostream>

using namespace std;

int main(){
	int sum(int*,int);
	int ia[5]={2,3,6,8,10};
	int sumOfArray;
	sumOfArray=sum(ia,5);
	cout<<"sum of array:"<<sumOfArray<<endl;
	return 0; 
}

int sum(int array[],int len){
	int iSum=0;
	for(int i=0;i<len;i++){
		iSum+=array[i];
	}
	return iSum;
} 
