#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	for(int n=1; n<=9; n++)
		cout <<setfill(' ') <<setw(n) <<" "
		     <<setfill('m') <<setw(-2*n+19) <<"m"
		     <<endl;
}

