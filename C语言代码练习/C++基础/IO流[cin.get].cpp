#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
	char letter;
	while(!cin.eof()) {
		letter =cin.get();
		letter =toupper(letter); //×ª³É´óĞ´
		if(letter=='Y') {
			cout <<"'Y' be met.";
			break;
		}
		cout <<letter;
	}
}
