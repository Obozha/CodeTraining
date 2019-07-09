#include<stdio.h>

void sort(int array[],int n);
void printArray(int array[],int n);

int main(){
	int a[10],i,length;
	printf("Enter array:\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\n");
	
	length=sizeof(a)/sizeof(a[0]);
	sort(a,length);
	printArray(a,length);
	return 0;
	 
}

void sort(int array[],int n){
	int i,j,k,t;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(array[j]<array[k])
				k=j;
		}
		t=array[k];
		array[k]=array[i];
		array[i]=t;
	}
}

void printArray(int array[],int n){
	int i;
	printf("数组序列为:\n");
	for(i=0;i<n;i++)
		printf("%d ",array[i]);
	printf("\n"); 
}
