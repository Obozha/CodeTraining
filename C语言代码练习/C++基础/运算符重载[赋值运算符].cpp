#include<iostream>
#include<string.h>

class Name{
	protected:
		char* pName;
		void copyName(char* pN);
		void deleteName();
	public:
		Name(){
			pName=0;
		}   // Ĭ�Ϲ��캯��
		
		Name(char* pn){
			copyName(pn);
			// ���캯�� 
		} 
		
		Name(Name& s){
			copyName(s.pName);
			// �������캯�� 
		} 
		
		~Name(){
			deleteName();
		}
		
		Name& operator=(){
			
		} 
}; 
