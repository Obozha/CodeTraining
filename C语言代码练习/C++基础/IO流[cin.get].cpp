#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
	char letter;
	while(!cin.eof()) {
		letter =cin.get();
		letter =toupper(letter); //ת�ɴ�д
		if(letter=='Y') {
			cout <<"'Y' be met.";
			break;
		}
		cout <<letter;
	}
}
