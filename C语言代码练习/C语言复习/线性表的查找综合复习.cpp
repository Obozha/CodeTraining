#include <iostream>
using namespace std;

//��¼����Ԫ������ElemType����
typedef struct {
	int key;    //�ؼ�����Ϊ����
	char* otherinfo;  //������
} ElemType;

//˳�������SSTable����
typedef struct {
	ElemType *R;    //�洢�ռ��ַ
	int length;    //��
} SSTable;

//˳����ң���˳���ST�в��ҹؼ���Ϊkey�ļ�¼�������ҳɹ������ؼ�¼�ڱ��е�λ�ã����򷵻�0
int Search_Seq(SSTable ST,int key) {
	ST.R[0].key=key;
	for(int i=ST.length;ST.R[i].key!=key;--i)
		return i;
}

//�۰���ң���˳���ST�в��ҹؼ���Ϊkey�ļ�¼�������ҳɹ������ؼ�¼�ڱ��е�λ�ã����򷵻�0
int Search_Bin(SSTable ST,int key) {
	//��ͬѧ�ǰѸò�����������
	int low=1,high=ST.length,mid;
	while(low<=high){
		mid=(low+high)/2;	 
		if(key==ST.R[mid].key) 
			return mid; // �ҵ�����Ԫ��
		else if(key<ST.R[mid].key)
			high=mid-1; // ������ǰһ�б���в��� 
		else
			low=mid+1;  // �����ں�һ�ӱ���в��� 
	}
	return 0;
}

//��������ļ�¼ֵ������˳���ST
void CreateTable(SSTable &ST) {
	int n,i;
	cout<<"�������¼�ĸ�����";
	cin>>n;
	ST.R =new ElemType[n+1];    //0�ŵ�Ԫ���ã���¼���±�1����ʼ���
	ST.length=n;                //����ST�ĳ���
	cout<<"������ÿ����¼�ؼ��ֵ�ֵ(����)���м��ÿո��س��ָ�"<<endl;
	for(i=1; i<=n; i++) {
		cin>>ST.R [i].key ;      //��������ÿ����¼�ؼ��ֵ�ֵ������ST.R[i]��
	}
}

int main() {
	SSTable ST;
	int a,pos;
	CreateTable(ST);        //����˳���ST

	cout<<"ִ��˳����ң�������Ҫ���ҵ�ֵ��";
	cin>>a;
	pos=Search_Seq(ST,a);    //��ST�н���˳����ҹؼ���Ϊa�ļ�¼��pos��ʾ���ҽ��
	if(pos>0)                //������ҽ��
		cout<<"���ҳɹ���"<<a<<"�ڱ��е�λ��Ϊ��"<<pos<<endl;
	else
		cout<<"���в�����ֵΪ"<<a<<"�ļ�¼��"<<endl;

	cout<<"\n\nִ���۰���ң�������Ҫ���ҵ�ֵ��";
	cin>>a;
	pos=Search_Bin(ST,a);     //��ST�н����۰���ҹؼ���Ϊa�ļ�¼��pos��ʾ���ҽ��
	if(pos>0)                 //������ҽ��
		cout<<"���ҳɹ���"<<a<<"�ڱ��е�λ��Ϊ��"<<pos<<endl;
	else
		cout<<"���в�����ֵΪ"<<a<<"�ļ�¼��"<<endl;

	return 0;
}




