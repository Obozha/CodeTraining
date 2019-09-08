#include<stdio.h>

void selection_sort(int *x,int len);
void swap(int*,int*);

int main(){
	int len = 10,i,arr[]={50,12,33,67,13,90,88,22,67,31};
	int *p;
	
	
	printf("before sorting:");
	for(p=&arr[0];p<(arr+len);p++){		// p设置为首地址  <arr+len [小于未地址] 
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
			if(*(x+j)<*(x+min)){ 		//  x一直指向首地址 
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
