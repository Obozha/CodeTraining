#include<iostream>
using namespace std;

int isnumber(char); // �˴���inline 
int main(){
	char c;
	while((c=cin.get())!='\n'){
		if(isnumber(c)){
			cout<<"you entered a digit\n";
		}else{
			cout<<"you entered a non_digit\n";
		}
	}
} 

inline int isnumber(char ch){
	// �˴���inline��������Ϊ��inline
	return (ch>='0'&&ch<='9')?1:0; 
}

