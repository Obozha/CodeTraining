#include<iostream>
using namespace std;
int main() {
   int *p=new int(202),&p2=*p;
   cout<<p2<<endl;
   delete &p2;  //���ߣ�delete p;  �ͷŶѿռ�
   return 0;
}

