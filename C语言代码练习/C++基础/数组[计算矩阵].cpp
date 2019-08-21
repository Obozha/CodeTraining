#include<iostream>
#include<iomanip>
using namespace std;

int a[3][4]= {{5,7,8,2},{-2,4,1,1},{1,2,3,4}};
int b[4][5]= {{4,-2,3,3,9},{4,3,8,-1,2},{2,3,5,2,7},{1,0,6,3,4}};
int c[3][5];
int MultiMatrix(int a[][4],int arow,int acol,
                int b[][5],int brow,int bcol,
                int c[][5],int crow,int ccol);

int main() {
	if(MultiMatrix(a,3,4,b,4,5,c,3,5)) {
		cout<<"illegal matrix multiplication.\n";
		return 1;
	}
	for(int i=0; i<3; i++) {
		for(int j=0; j<5; j++)cout<<setw(5)<<c[i][j];
		cout<<endl;
	}
	return 0;

}

int MultiMatrix(int a[][4],int arow,int acol,
                int b[][5],int brow,int bcol,
                int c[][5],int crow,int ccol) {
	if(acol!=brow)
		return 1;
	if(crow!=arow)
		return 1;
	if(ccol!=bcol)
		return 1;
	for(int i=0; i<crow; i++)
		for(int j=0; j<ccol; j++) {
			c[i][j]=0;
			for(int n=0; n<acol; n++)
				c[i][j]+=a[i][n]*b[n][j];
		}
	return 0;
}
