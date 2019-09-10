#include<iostream>
using namespace std;

class Base1{ // ����� 
	private:
		int a,b;
	public:
		Base1(int aa=0,int bb=0){
			// ���캯�����Ǵ�ȱʡֵ���������޲���
			a=aa;
			b=bb;
			cout<<"Base1 class"<<endl; 
		} 
	
		void Show(){
			cout<<"Base1:a="<<a<<"b="<<b<<endl;
		}
};

class Base2{
	public:
		Base2(){
			cout<<"Base2 class"<<endl;
		}
		
		void show2(){
			cout<<"Base2:"<<endl;
		}
};

class Level1:public Base2,virtual public Base1{
	public:
		Level1(int a,int b):Base1(a,b){
			cout<<"Level1 class!"<<endl;
		}	
};

class Level2:public Base2,virtual public Base1{
	public:
		Level2(int a,int b):Base1(a,b){
			cout<<"Level2 class!"<<endl;
		}
};

class Lastlevel:public Level1,virtual public Level2{
	public:
		Lastlevel(int a,int b):Level1(a,b),Level2(a,b),Base1(a,b){
			//Lastlevel(int a,int b):Level1(a,b), Level2(a,b), Base1(a,b)    
			cout<<"Lastlevel class!"<<endl;	
		}	
};

int main(){
	Lastlevel obj(7,9);
	obj.Show();
	// ֱ�ӵ��ü�ӻ���base�Ĺ��г�Աshow()���޶�����
	// obj.show2(); // error
	// ���ʼ�ӳ�Աbase2�Ĺ��г�Աshow()2 ���ڶ����� 
}
