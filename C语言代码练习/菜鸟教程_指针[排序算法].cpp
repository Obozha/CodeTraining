#include<stdio.h>

void swap(int*,int*);
void selection_sort(int arr[],int len); 

int main(){
	int i,arr[] = {10,9,3,2,5,11,7,5,4,8};
	selection_sort(arr,10);

	for(i=0;i<10;i++){
		printf("%d ",arr[i]);
	}

} 

void swap(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void selection_sort(int arr[],int len){
	int i,j,min,t;
	for(i=0;i<len-1;i++){ 
		min=i;
		for(j=i+1;j<len;j++){ 		// �߷�δ�����Ԫ�� 
			if(arr[j]<arr[min]){	// �ҵ�Ŀǰ��Сֵ 
				min=j;				// ��¼��Сֵ 
			}
		}
		swap(&arr[min],&arr[i]); 	// ������ 
	} 
}


//void selection_sort(int arr[],int len){
//	int i,j,min;
//	
//	for(i=0;i<len-1;i++){
//		min = i;
//		for(j=i+1;j<len;j++){ 		// �߷�δ�����Ԫ�� 
//			if(arr[j]<arr[min]){	// �ҵ�Ŀǰ��Сֵ 
//				min=j; 				// ��¼��Сֵ 
//			}
//			swap(&arr[min],&arr[i]); // ������ 
//		}
//	}
//}
