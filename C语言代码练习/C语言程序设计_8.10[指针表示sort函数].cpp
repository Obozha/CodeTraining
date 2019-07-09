#include<stdio.h>

void selection_sort(int *x,int len);
void swap(int*,int*);

int main(){
	int len = 10,i,arr[]={50,12,33,67,13,90,88,22,67,31};
	int *p;
	
	
	printf("before sorting:");
	for(p=&arr[0];p<(arr+len);p++){		// p����Ϊ�׵�ַ  <arr+len [С��δ��ַ] 
		printf("%d ",*p);
	}
	
	p=arr;
	
	selection_sort(p,len);
	printf("\nsort finish:");
	for(p=&arr[0];p<(arr+len);p++){
		printf("%d ",*p);
	}
	
}

void selection_sort(int *x,int len){
	int i,j,min;
	for(i=0;i<len-1;i++){
		min=i;
		for(j=i+1;j<len;j++){
			if(*(x+j)<*(x+min)){ 		//  xһֱָ���׵�ַ 
				min=j;
			}
			// printf("%p ",x); 
		}
		if(min!=i){
			swap(x+min,x+i);
		}
		
	}
}

void swap(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;	
}
