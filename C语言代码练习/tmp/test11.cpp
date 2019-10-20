#include<iostream>
using namespace std;

void findMinindex(int *a,int len);

int main(){
	int a[]={35,98,54,29,12,35,14,54,57,88};
	findMinindex(a,sizeof(a)/sizeof(int));

}

void findMinindex(int *a,int len){
	int min,index;
	min=a[0];
	for(int i=1;i<len;i++){
		if(a[i]<min){
			min=a[i];
			index=i;
		}
	}
	cout<<"最小值是"<<min<<"，下标为"<<index<<endl;
	
} 
