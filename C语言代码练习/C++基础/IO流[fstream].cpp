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
	//���ļ�abc1.txt��д��һ������

	os2<<99.12<<endl<<"jiao_tong"<<endl;
	//���ļ�abc2.txt��д���������
	
	os1.close();
	os2.close();
	
	ifstream is1;   //������ļ���ָ��is1
	is1.open("abc1.txt");
	is1>>a>>b>>i;
	cout<<a<<" "<<b<<"   "<<(i*2)<<endl;
	//�����Shang hai 246
	is1.close(); //�ر��ļ���������is1��Ȼ����

	is1.open("abc2.txt");
	is1>>x>>a;
	cout<<x<<"   "<<a<<endl;     //�����99.12  jiao_tong
	is1.close();
	
	fstream fs("abc1.txt",ios::in|ios::out);
	fs>>a>>b>>i;     //������ļ�ָ��ָ����һ��
	cout<<"fs: "<<a<<" "<<b<<"   "<<i<<endl;
	//�����fs: shang hai   123
	fs<<"kkkkk ppp "<<777<<endl;
	//���ļ�abc1.txt����д��һ������
	fs.close();    //�ļ�abc1.txt��abc2.txt������

	fs.open("abc1.txt",ios::in);
	//��ֻ����ʽ���ļ�
	fs>>a>>b>>i;
	cout<<"fs: "<<a<<" "<<b<<"   "<<i<<endl;
	fs>>a>>b>>i;
	cout<<"fs: "<<a<<" "<<b<<"   "<<i<<endl;
	fs.close();
}

