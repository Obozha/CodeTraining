#include<iostream>
using namespace std;

void ff(int a,int b,int(*p)(int,int)){
	/* ����ָ��p��ָ�����������β�������������ֵ�ú�����ָ�� */
	int x;
	x=(*p)(a,b);  // �� x=p(a,b);
	cout<<x<<endl; 
}

int min(int a,int b){
	return (a>b?b:a);
}

int max(int a,int b){
	return (a>b?a:b);
}

int sum(int a,int b){
	return (a+b);
}

int main(){
	int a,b,c;
	cout<<"����������������һ������"<<endl;
	cin>>a>>b>>c;
	if(c==1)
		ff(a,b,max);
	else if(c==2)
		ff(a,b,min);
	else
		ff(a,b,sum);	
} 
