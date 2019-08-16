#include<iostream>

using namespace std;
int maximum(int[],int);
int main() {
	int sg[3][4]= {{68,77,73,86},{87,96,78,89},{90,70,81,86}};
	cout<<"the max greade is "<<maximum(&sg[0][0],3*4)<<endl;
	return 0;
}

int maximum(int grade[],int num) {
	int max=0; // 局部变量必须赋值 
	for(int i=0; i<num; i++) {
		if(grade[i]>max) {
			max=grade[i];
		}
	}
	return max;
}
