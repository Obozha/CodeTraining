#include<iostream>
using namespace std;


class Increase {
	public:
		Increase(int x):value(x) {
		}

		friend Increase& operator++(Increase&);    // ǰ����
		friend Increase operator++(Increase&,int); // ������

		void display() {
			cout<<"the value is"<<value<<endl;
		}

	private:
		int value;
};

Increase& operator++(Increase& a) {
	a.value++;
	return a;
}

Increase operator++(Increase& a,int c) {
	Increase temp(a); // ͨ��������������ԭ�ж���ֵ
	a.value++;		  // ԭ�ж��������޸�
	return temp; 	  // ����ԭ�ж���ֵ
}

int main() {
	Increase n(20);
	n.display();
	(n++).display();              //��ʾ��ʱ����ֵ
	n.display();                     //��ʾԭ�ж���
	++n;
	n.display();
	++(++n);
	n.display();
	(n++)++;
	//�ڶ���������������ʱ�������
	n.display();
}


