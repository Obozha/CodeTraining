#include<stdio.h>

int main(){
	int i,j,temp;
	int a[]={3,4,5,1,3,89,21,45,88,12};
	for(i=0;i<10;i++){ // i���� length-1 
		int minindex=i; // ������С���� 
		for(j=i+1;j<=9;j++){  // ͨ���Ƚϻ����Сֵ���� 
			if(a[j]<a[minindex]){
				minindex=j;
			}
		}
		if(minindex!=i){ //  ����С�Ļ���ǰ�� 
			temp=a[i];
			a[i]=a[minindex];
			a[minindex]=temp;
		}
	}
	
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	
}
