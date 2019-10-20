//**********************
//**    ch19_8.cpp    **
//**********************

#include <iostream>
using namespace std;

int main()
{
	
  for(int n =0; n <=9; n++){
    for(int k =1; k <=n; k++) cout <<" ";
    for(int k =1; k <=19-2*n; k++) cout <<"m";
    cout <<endl;
  }
}

