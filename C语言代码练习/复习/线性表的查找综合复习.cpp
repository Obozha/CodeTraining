#include <iostream>
using namespace std;

//记录数据元素类型ElemType定义
typedef struct {
	int key;    //关键字域，为整形
	char* otherinfo;  //其它域
} ElemType;

//顺序表类型SSTable定义
typedef struct {
	ElemType *R;    //存储空间基址
	int length;    //表长
} SSTable;

//顺序查找，在顺序表ST中查找关键字为key的记录，若查找成功，返回记录在表中的位置，否则返回0
int Search_Seq(SSTable ST,int key) {
	ST.R[0].key=key;
	for(int i=ST.length;ST.R[i].key!=key;--i)
		return i;
}

//折半查找，在顺序表ST中查找关键字为key的记录，若查找成功，返回记录在表中的位置，否则返回0
int Search_Bin(SSTable ST,int key) {
	//请同学们把该操作补充完整
	int low=1,high=ST.length,mid;
	while(low<=high){
		mid=(low+high)/2;	 
		if(key==ST.R[mid].key) 
			return mid; // 找到待查元素
		else if(key<ST.R[mid].key)
			high=mid-1; // 继续在前一列表进行查找 
		else
			low=mid+1;  // 继续在后一子表进行查找 
	}
	return 0;
}

//根据输入的记录值，创建顺序表ST
void CreateTable(SSTable &ST) {
	int n,i;
	cout<<"请输入记录的个数：";
	cin>>n;
	ST.R =new ElemType[n+1];    //0号单元不用，记录从下标1处开始存放
	ST.length=n;                //设置ST的长度
	cout<<"请输入每个记录关键字的值(整形)，中间用空格或回车分隔"<<endl;
	for(i=1; i<=n; i++) {
		cin>>ST.R [i].key ;      //依次输入每个记录关键字的值，存入ST.R[i]中
	}
}

int main() {
	SSTable ST;
	int a,pos;
	CreateTable(ST);        //创建顺序表ST

	cout<<"执行顺序查找，请输入要查找的值：";
	cin>>a;
	pos=Search_Seq(ST,a);    //在ST中进行顺序查找关键字为a的记录，pos表示查找结果
	if(pos>0)                //输出查找结果
		cout<<"查找成功！"<<a<<"在表中的位置为："<<pos<<endl;
	else
		cout<<"表中不存在值为"<<a<<"的记录！"<<endl;

	cout<<"\n\n执行折半查找，请输入要查找的值：";
	cin>>a;
	pos=Search_Bin(ST,a);     //在ST中进行折半查找关键字为a的记录，pos表示查找结果
	if(pos>0)                 //输出查找结果
		cout<<"查找成功！"<<a<<"在表中的位置为："<<pos<<endl;
	else
		cout<<"表中不存在值为"<<a<<"的记录！"<<endl;

	return 0;
}




