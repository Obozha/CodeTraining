#include<iostream>
#include<iomanip>
using namespace std;
void printArr(int arr[],int len);

int main(){
	int iArray[10];
	iArray[0]=1;
	iArray[1]=1;
	for(int i=2;i<10;i++){
		iArray[i]=iArray[i-1]+iArray[i-2];
		// ... 
	}
	printArr(iArray,10);
} 

void printArr(int arr[],int len){
	for(int i=0;i<len;i++){
		cout<<setw(5)<<arr[i];
	}
}
