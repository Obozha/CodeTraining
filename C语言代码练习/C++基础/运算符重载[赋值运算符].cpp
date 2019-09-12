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
		}   // 默认构造函数
		
		Name(char* pn){
			copyName(pn);
			// 构造函数 
		} 
		
		Name(Name& s){
			copyName(s.pName);
			// 拷贝构造函数 
		} 
		
		~Name(){
			deleteName();
		}
		
		Name& operator=(){
			
		} 
}; 
