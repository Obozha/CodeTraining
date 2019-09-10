#include<iostream>
using namespace std;

class Display { //��ʾ���࣬�ǳ�����
	public:
		virtual void init()=0;  //���麯��
		virtual void write(const char * pString)=0; //����ַ���
};

class Monochrome:public Display { //��ɫ��ʾ����
		virtual void init();
		virtual void write(const char * pString);
};
void Monochrome::init() { 
	cout<<"init"<<endl;
}

void Monochrome::write(const char * pSring) { 
	cout<<pSring<<endl;
}

int main(){
	Display *d;
	Monochrome m;
	d=&m; 
	d->init();
	d->write("HelloWorld"); 
}
