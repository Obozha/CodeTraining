#include<iostream>
using namespace std;
int main() {
   int *p=new int(202),&p2=*p;
   cout<<p2<<endl;
   delete &p2;  //或者：delete p;  释放堆空间
   return 0;
}

