#include<fstream>
using namespace std; 
void fn() {
	ofstream myf("myname.txt");    	//ios::out|ios::trunc·½Ê½
	myf <<"In each of the following questions, a related pair\n"
	    <<"of words or phrases is followed by five lettered pairs\n"
	    <<"of words or phrases.\n";
	myf.close();
}

int main() {
	fn();
}

