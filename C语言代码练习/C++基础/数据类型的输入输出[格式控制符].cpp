#include<iostream>
#include<iomanip> // Ҫ�õ���ʽ���Ʒ�
using namespace std;
int main(){
	  double amount = 22.0/7;
  cout <<amount <<endl; 
  cout <<setprecision(0) <<amount <<endl
           <<setprecision(1) <<amount <<endl
           <<setprecision(2) <<amount <<endl
           <<setprecision(3) <<amount <<endl
           <<setprecision(4) <<amount <<endl; 

  cout <<setiosflags(ios::fixed); //����Ϊ����С�����
  cout <<setprecision(8) <<amount <<endl;
           
  cout <<setiosflags(ios::scientific) 
          <<amount <<endl;
  cout <<setprecision(6);    //�������ó�ԭĬ������

} 
