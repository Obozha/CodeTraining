#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20     //顺序表最大长度

typedef struct {
	int key;           //关键字项，关键字类型为整形
	char *otherinfo;   //其它数据项
} RedType;    //记录类型

typedef struct {
	RedType r[MAXSIZE+1];     //0号单元闲置
	int length;               //顺序表长度
} SqList;    //顺序表类型


//对顺序表L中的记录进行直接插入排序
void InsertSort(SqList &L) {
	for(int i=2; i<=L.length; i++) {       		 // 进行L.length-1趟排序
		if(L.r[i].key<L.r[i-1].key) { 			 // 将L.r[i]插入有序子表
			L.r[0]=L.r[i];
			int j;					     // 将待插入的纪录暂存到监视哨中
			for(j=i-1; L.r[0].key<L.r[j].key; j--) // 从后向前寻找插入位置
				L.r[j+1]=L.r[j];  				 // 纪录向后移动
			L.r[j+1]=L.r[0]; 					 // 插入到正确位置
		}
	}
}

//对顺序表L中的记录进行折半插入排序
void BInsertSort(SqList &L) {
	for(int i=2; i<=L.length; i++) {
		L.r[0]=L.r[i]; 					// 将L.r[i]暂存到L.r[0]
		int low=1,high=i-1;
		while(low<=high) { 				// 在r[low..high]中折半查找插入位置
			int m=(low+high)/2;
			if(L.r[0].key<L.r[m].key)
				high=m-1;   			// 插入点在低半区
			else
				low=m+1;				// 插入点在高半区
		}
		for(int j=i-1; j>=high+1; --j)
			L.r[j+1]=L.r[j];			// 记录后移
		L.r[high+1]=L.r[0];				// 插入
	}
}

//对顺序表L中的记录进行一趟增量为dk的希尔排序
void ShellInsert(SqList &L,int dk) {
	//请补充该操作
	for(int i=dk+1; i<=L.length; i++) {
		if(L.r[i].key<L.r[i-dk].key) { // 将L.r[i]插入有序子表
			L.r[0]=L.r[i];            // 用L.r[0]暂存待插入记录L.r[i]
			int j;
			for(j=i-dk; j>0&&L.r[0].key<L.r[j].key; j-=dk)
				L.r[j+dk]=L.r[j];     // 记录后移
			L.r[j+dk]=L.r[0];		  // 插入正确的位置
		}
	}
}

//对顺序表L中的记录按增量序列（存储在数组dt中）进行t趟希尔排序
void ShellSort(SqList &L,int dt[],int t) {
	//请补充该操作
	for(int k=0; k<t; k++)
		ShellInsert(L,dt[k]);
	// 一趟增量为dt[k]的希尔插入排序
}

//对顺序表L中的记录进行冒泡排序
void BubbleSort(SqList &L) {
	//请补充该操作
	int flag=1,j;
	for(int i=L.length-1; i>=1&&flag; i--) { // 控制排序趟数
		flag=0; // 每趟排序开始时，将flag
		for(j=1; j<=i; j++) { // 从前向后扫描本趟无序区[1...i+1]
			if(L.r[j].key>L.r[j+1].key) { // 若相邻记录是逆序，交换之
				flag=1;			// 本趟排序中发生了交换，将flag置为1
				RedType t=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=t;
			}
		}
	}
}

//对顺序表L中的子表L.r[low...high]进行一次划分，并返回枢轴位置
int Partition(SqList &L,int low,int high) {
	// 对顺序表L中[low..high]进行一趟快速排序，并返回枢轴记录
	// 所在位置，使得在它之前的记录的关键字均不大于它的关键字
	// 而在它之后的记录的关键字均不小于它的关键字
	L.r[0]=L.r[low];      // 将枢轴记录移至数组的闲置分量
	int pivotkey=L.r[low].key;// 枢轴记录关键字
	while(low<high) {  	 // 从表的两端交替地向中间扫描
		while(low<high&&L.r[high].key>=pivotkey)
			--high;
		L.r[low]=L.r[high]; // 将比枢轴记录小的记录移到低端
		while(low<high&&L.r[low].key<=pivotkey)
			++low;
		L.r[high]=L.r[low]; // 将比枢轴记录大的记录移到高处
	}
	L.r[low]=L.r[0]; // 将比枢轴记录大的记录移动到高端
	return low;
}


//对顺序表L中的子序列L.r[low...high]进行快速排序
void QSort(SqList &L,int low,int high) {
	//请补充该操作
	if(low<high) { // 长度大于1
		int pivotloc=Partition(L,low,high);
		// 将L.r[row...high]一分为二，pivotloc为枢轴位置
		QSort(L,low,pivotloc-1); // 对左子序列递归排序
		QSort(L,pivotloc+1,high); // 对左子序列递归排序
	}
}

//对顺序表L中的记录进行快速排序
void QuickSort(SqList &L) {
	//请补充该操作
	QSort(L,1,L.length);
}

//对顺序表L中的记录进行简单选择排序
void SelectSort(SqList &L) {
	//请补充该操作
	for(int i=1; i<L.length; i++) { // 排序趟数
		// 在L.r
		int k=i;
		for(int j=i+1; j<=L.length; j++) {
			if(L.r[j].key<L.r[k].key)
				k=j;
		}
		if(i!=k) {
			RedType t=L.r[i];
			L.r[i]=L.r[k];
			L.r[k]=t;
		} // 交换L.r[i]和L.r[k]
	} // for i
}

//堆的调整，假设L.r[s+1...m]已经是一个大根堆，该操作将L.r[s...m]调整为以L.r[s]为根的大根堆
void HeapAdjust(SqList &L,int s,int m) {
	//请补充该操作
	//假设r[s+1..m]已经是堆，将r[s..m]调整为以r[s]为根的大根堆
	RedType rc;
	int j;
	rc=L.r[s];
	for(j=2*s; j<=m; j*=2) {
		//沿key较大的孩子结点向下筛选
		if(j<m&&L.r[j].key<L.r[j+1].key) ++j;		//j为key较大的记录的下标
		if(rc.key>=L.r[j].key) break;      			//rc应插入在位置s上
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=rc;

}

//把顺序表L中的无序记录序列建成大根堆
void CreatHeap(SqList &L) {
	//请补充该操作
	int i,n;
	n=L.length;
	for(i=n/2; i>0; i--)
		HeapAdjust(L,i,n);
}

//对顺序表L中的记录进行堆排序
void HeapSort(SqList &L) {
	//请补充该操作
	//对顺序表L进行堆排序
	int i;
	RedType x;
	CreatHeap(L);              					//把无序序列L.r[1..L.length]建成大根堆
	for(i=L.length; i>1; --i) {
		x=L.r[1];               				//将堆顶记录和当前未经排序子序列L.r[1..i]中最后一个记录互换
		L.r[1]=L.r[i];
		L.r[i]=x;
		HeapAdjust(L,1,i-1);					//将L.r[1..i-1]重新调整为大根堆
	}//for
}

//将有序表R[low...mid]和R[mid+1...high]归并为有序表T[low...high]
void Merge(RedType R[],RedType T[],int low,int mid,int high) {
	//请补充该操作
	int i=low,j=mid+1,k=low;
	while(i<=mid&&j<=high) {
		if(R[i].key<R[j].key)
			T[k++]=R[i++];
		else
			T[k++]=R[j++];
	}
	while(i<=mid)
		T[k++]=R[i++];
	while(j<=high)
		T[k++]=R[j++];
}

//将R[low...high]中的记录归并排序后放入T[low...high]中
void MSort(RedType R[],RedType T[],int low,int high) {
	//请补充该操作
	RedType *S=new RedType[MAXSIZE];
	if(low==high)
		T[low]=R[low];
	else {
		int mid=(low+high)/2;
		MSort(R,S,low,mid);
		MSort(R,S,mid+1,high);
		Merge(S,T,low,mid,high);
	}
}

//对顺序表L中的记录进行归并排序
void MergeSort(SqList &L) {
	//请补充该操作
	MSort(L.r,L.r,1,L.length);
}
//创建顺序表：向顺序表L中添加10个记录，记录的关键字为1-100范围内的随机整数
void CreateList(SqList &L) {
	int i;
	srand(time(0));
	for(i=1; i<=10; i++) {
		L.r[i].key =rand()%100+1;
	}
	L.length =10;
}

//输出顺序表L中各记录关键字的值，中间用空格分隔
void PrintList(SqList L) {
	int i;
	for(i=1; i<=L.length ; i++) {
		cout<<L.r[i].key <<"  ";
	}
	cout<<endl;
}

//程序菜单
void showmenu() {
	cout<<endl;
	cout<<"*************排序方法************************"<<endl;
	cout<<"1. 直接插入排序\t2. 折半插入排序"<<endl;
	cout<<"3. 希尔排序\t4. 冒泡排序"<<endl;
	cout<<"5. 快速排序\t6. 简单选择排序"<<endl;
	cout<<"7. 堆排序\t8. 二路归并排序"<<endl;
	cout<<"0.退出"<<endl;
	cout<<"请选择要执行的排序方法序号"<<endl;

}

int main() {
	SqList L;
	int n,dt[3]= {5,3,1};   //dt中存放的是希尔排序时使用的三个增量
	CreateList(L);         //创建长度为10的顺序表L，表中记录的关键字为1-100范围内的随机整数
	showmenu();
	cin>>n;         //输出选择的排序方法序号
	while(n!=0) {   //循环显示菜单，按0结束程序
		if(n>=1&&n<=8) {
			cout<<"待排序记录初始关键字为："<<endl;
			PrintList(L);        //输出排序前表中各记录关键字的值
		}
		switch(n) {   //根据选择的序号调用不同的排序方法
			case 1:
				cout<<"直接插入排序的结果为："<<endl;
				InsertSort(L);    //直接插入排序
				PrintList(L);     //输出排序后各记录关键字的值
				break;
			case 2:
				cout<<"折半插入排序的结果为："<<endl;
				BInsertSort(L);   //折半插入排序
				PrintList(L);
				break;
			case 3:
				cout<<"希尔排序的结果为："<<endl;
				ShellSort(L,dt,3);    //希尔排序，（3趟）
				PrintList(L);
				break;
			case 4:
				cout<<"冒泡排序的结果为："<<endl;
				BubbleSort(L);     //冒泡排序
				PrintList(L);
				break;
			case 5:
				cout<<"快速排序的结果为："<<endl;
				QuickSort(L);    //快速排序
				PrintList(L);
				break;
			case 6:
				cout<<"简单选择排序的结果为："<<endl;
				SelectSort(L);     //简单选择排序
				PrintList(L);
				break;
			case 7:
				cout<<"堆排序的结果为："<<endl;
				HeapSort(L);    //堆排序
				PrintList(L);
				break;
			case 8:
				cout<<"快速排序的结果为："<<endl;
				MergeSort(L);    //二路归并排序
				PrintList(L);
				break;
			default:
				cout<<"序号选择错误，请重新选择！"<<endl;
				break;

		}
		CreateList(L);    //每次排序后，重置L中的10个记录
		showmenu();
		cin>>n;
		system("cls");   //清屏
	}
}
