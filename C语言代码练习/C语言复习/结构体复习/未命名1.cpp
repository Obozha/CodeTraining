void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC){
	// 已知单链表LA和LB的元素按值非递减排列
	// 归并LA和LB得到新的单链表LC，LC的元素也按值非递减排列
	pa=LA->next;pb=LB->next; // pa和pb的初值分别指向两个表的第一个结点
	LC=LA;
	pc=LC;
	while(pa&&pb){
		// LA和LB均未到达表尾，依次”摘取“两表中值较小的结点插入到LC的最后
		if(pa->data<=pb->data){ // ”摘取“pa所指结点 
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		} else{
			pc->next=pb;  
			pc=pb;
			pb=pb->next;
		}
	} 
	pc->next=pa?pa:pb; // 将非空表的剩余段插入到pc所指结点之后 
	delete LB; 		   // 释放LB的结点 
} 




