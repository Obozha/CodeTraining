#include <string.h>
class Student {
	public:
		Student(const char* pName) {
			strncpy(name,pName,sizeof(name));
			name[sizeof(name)-1]='\0';
		}
		Student( ) { }
	protected:
		char name[20];
};
int  main( ) {
	Student noName;          //ok
	Student ss("Jenny");     //ok
}

