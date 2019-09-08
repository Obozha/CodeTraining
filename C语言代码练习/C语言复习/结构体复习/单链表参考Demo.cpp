//--------
/** 功能：应用C语言实现的单链表的各项操作 
  *
  *		1.建立节点 
  *		2.打印单链表 
  *		3.尾插 
  *		4.尾删 
  *		5.头插 
  *		6.头删 
  *		7.清空整个链表 
  *		8.获取链表长度 
  *		9.查找数据 
  *		10.在某位置后插入数据
  *		11.删除某位置的数据
  *		12.删除一个无头单链表的非尾节点 
  *		13.在无头单链表的一个非头节点前插入一个节点
  *		14.查找中间节点 
  * 	15.查找倒数第k个节点（要求只能遍历一次）
  * 	16.倒着打印单链表
  *		17.逆置单链表
  *		18.合并两个有序链表（合并后依然有序）
  *		19.冒泡排序 
*/

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct SListNode{
	DataType data; //数据
	struct SListNode* next; // 指向下一个节点的指针 
}SListNode;

// 如果要修改链表就必须加引用
SListNode* _BuyNode(DataType x); // 建立节点 

