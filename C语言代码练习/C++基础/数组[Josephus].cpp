#include<iostream>

using namespace std;

int main() {
	// ����С������
	const int num=10;  // С����
	int interval; // ÿ����interval
	int a[num];   // С������
	// ��С�����
	for(int i=0; i<num; i++) // С���ı��ֻ��С���й�
		a[i]=i+1;
	// ������С�����
	cout<<endl<<"Please input the interval\n";
	cin>>interval; // ����һ��С������
	for(int i=0; i<num; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	int k=1; // ��ʶ�����k���뿪��С��
	int i=-1; // �����±꣨��һ��ֵ0���ǵ�һ��С�����±꣩
	// �����ʤǰ��С��
	while(1) {
		// ��Ȧ����interval��С��
		for(int j=0; j<interval;) {
			i=(i+1)%num; // ���±��1��ģ
			if(a[i]!=0)  // �����Ԫ�ص�С����Ȧ�У������������Ч
				j++;
		}
		if(k==num)
			break; // ��С�������һ����ʤ���ߣ���
		cout<<a[i]<<","; // ����뿪��С�����
		a[i]=0; // ��ʶС�����뿪
		k++; // ׼��������һ��С�� 
	}
	// break�����ת���� 
	cout<<"\nNo."<<a[i]<< " boy\'s won"<<endl; // ���ʤ���� 
}
