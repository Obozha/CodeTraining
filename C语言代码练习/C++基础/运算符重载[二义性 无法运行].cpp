class B;
class A{
	public:
		A(B& b){};      // 用B类对象构造A类对象(B类对象转换成A类对象) 
};

class B{
	public:
		operator A(); // 将B类对象转换成A类对象 
};

int main(){
	B sb;
	A a=A(sb); // error A(sb)是构造函数转换? 
}
