#include<iostream>
using namespace std;

class RMB{
	private:
		unsigned int yuan; // Ԫ
		unsigned int jf;   // �Ƿ� 
	public:
		RMB(double d){
			yuan=d;
			jf=(d-yuan)*100;
		}
		
		RMB interest(double rate); // ������Ϣ 
		RMB add(RMB &d); // �����Ҽ� 
		RMB operator+(RMB& d){ // ����Ҽӵ���������� 
			return RMB(yuan+d.yuan+(jf+d.jf)/100.0);
		}
		RMB operator*(double rate){
			return RMB((yuan+jf/100.0)*rate);
		}
		
		void display(){
			cout <<(yuan + jf / 100.0) << endl; 
		}
};

RMB RMB::interest(double rate){ // ������Ϣ 
	return RMB((yuan+jf/100.0)*rate);
}

RMB RMB::add(RMB& d){ // ����Ҽ�
 	return RMB(yuan+d.yuan+jf/100.0+d.jf/100.0); 
} 

// �����Ǽ���Ӧ������ҵ������汾
RMB expense1(RMB& principle,double rate){ // ���㱾Ϣ�� 
	RMB interest=principle.interest(rate);	
	return principle.add(interest);
} 

RMB expense2(RMB& principle,double rate){ // ���㱾Ϣ�� 
	RMB interest=principle*rate; // �������Ϣ 
	return principle+interest;   // ��������  
}

int main(){
	RMB x=10000.0;
	double yrate=0.035;
	expense1(x,yrate).display();
	expense2(x,yrate).display();
}
