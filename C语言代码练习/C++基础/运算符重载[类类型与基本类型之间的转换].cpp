#include<iostream>
using namespace std;

class Counter{
	private:
		int v1;
		char v2;
	public:
		Counter(int v=0,char vv='?'){
			v1=v;
			v2=vv;
		}
		
		operator char(){
			return v2; // ����ת������ 
		}
		
		operator int(){
			return v1; // ����ת������ 
		}
		
		void display(){
			cout<<"Counter:v1="<<v1<<" v2="<<v2<<endl;
		}
		
		friend Counter fn(Counter c); // ��Ԫ���� 
};

Counter fn(Counter c){ // ��Ԫ���� 
	c.v1=c.v1*2;
	return c;
} 

int main(){
	char x;
	int y;
	Counter c1(64,'%'),c2(99,'@');
	c1.display();
	c2.display();
	c2=fn(12345); // ���캯������ʽת�� 
	c2.display();
	x=(char)c1; // ����ת������ 
	y=(int)c1;	// ����ת������
	cout<<x<<" "<<y<<endl; 
}
