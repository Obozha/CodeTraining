class B;
class A{
	public:
		A(B& b){};      // ��B�������A�����(B�����ת����A�����) 
};

class B{
	public:
		operator A(); // ��B�����ת����A����� 
};

int main(){
	B sb;
	A a=A(sb); // error A(sb)�ǹ��캯��ת��? 
}
