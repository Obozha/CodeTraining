#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int i;
	double x;
	char a[10],b[10];
	ofstream os1,os2("abc2.txt");
	os1.open("abc1.txt");

	os1<<"shang hai 123"<<endl;
	//向文件abc1.txt中写入一行数据

	os2<<99.12<<endl<<"jiao_tong"<<endl;
	//向文件abc2.txt中写入二行数据
	
	os1.close();
	os2.close();
	
	ifstream is1;   //定义读文件的指针is1
	is1.open("abc1.txt");
	is1>>a>>b>>i;
	cout<<a<<" "<<b<<"   "<<(i*2)<<endl;
	//输出：Shang hai 246
	is1.close(); //关闭文件，但对象is1依然存在

	is1.open("abc2.txt");
	is1>>x>>a;
	cout<<x<<"   "<<a<<endl;     //输出：99.12  jiao_tong
	is1.close();
	
	fstream fs("abc1.txt",ios::in|ios::out);
	fs>>a>>b>>i;     //读完后文件指针指向下一个
	cout<<"fs: "<<a<<" "<<b<<"   "<<i<<endl;
	//输出：fs: shang hai   123
	fs<<"kkkkk ppp "<<777<<endl;
	//向文件abc1.txt中再写入一行数据
	fs.close();    //文件abc1.txt、abc2.txt的内容

	fs.open("abc1.txt",ios::in);
	//以只读方式打开文件
	fs>>a>>b>>i;
	cout<<"fs: "<<a<<" "<<b<<"   "<<i<<endl;
	fs>>a>>b>>i;
	cout<<"fs: "<<a<<" "<<b<<"   "<<i<<endl;
	fs.close();
}

