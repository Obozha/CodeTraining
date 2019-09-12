#include<iostream>
using namespace std;

class Increase{
	private:
		int value;
	public:
		Increase(int x):value(x){}; // ���캯�� 
		
		Increase& operator++();  // ǰ����
		Increase operator++(int);// ������ 
		 
		void display(){
			cout<<"the value is "<<value<<endl;
		} 
};

Increase& Increase::operator++(){ // ǰ���� 
	value++;
	return *this;
}

Increase Increase::operator++(int){// ������ 
	Increase temp(*this); // ��ʱ�������ж���ֵ
	value++; 
	return temp;		  // ����ԭ�ж���ֵ 
}

int main(){
	Increase n(20);
	n.display();
	
	(n++).display();
	// ���ﷵ�ص�����ʱ�������ʾ20  
	
	n.display();
	// �����Ǹոպ���������n 
	
	++n;
	n.display();
	// ������ǰ�������� 
	
	++(++n);
	n.display();
	// 24 ��һ��ǰ�����᷵����ֵ��Ȼ���ٴ����� 
	
	(n++)++; 
	n.display(); 
	// 25 ��һ�λ�������Ȼ�󷵻���ʱ�������ڶ��������ͼӵ���ʱ������ 
}
