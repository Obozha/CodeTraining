void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC){
	// ��֪������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	// �鲢LA��LB�õ��µĵ�����LC��LC��Ԫ��Ҳ��ֵ�ǵݼ�����
	pa=LA->next;pb=LB->next; // pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ�����
	LC=LA;
	pc=LC;
	while(pa&&pb){
		// LA��LB��δ�����β�����Ρ�ժȡ��������ֵ��С�Ľ����뵽LC�����
		if(pa->data<=pb->data){ // ��ժȡ��pa��ָ��� 
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		} else{
			pc->next=pb;  
			pc=pb;
			pb=pb->next;
		}
	} 
	pc->next=pa?pa:pb; // ���ǿձ��ʣ��β��뵽pc��ָ���֮�� 
	delete LB; 		   // �ͷ�LB�Ľ�� 
} 




