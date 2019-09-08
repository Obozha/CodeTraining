#include<stdio.h>

int main(){
	int i,j,temp;
	int a[]={3,4,5,1,3,89,21,45,88,12};
	for(i=0;i<10;i++){ // i趟数 length-1 
		int minindex=i; // 设置最小坐标 
		for(j=i+1;j<=9;j++){  // 通过比较获得最小值坐标 
			if(a[j]<a[minindex]){
				minindex=j;
			}
		}
		if(minindex!=i){ //  把最小的换到前方 
			temp=a[i];
			a[i]=a[minindex];
			a[minindex]=temp;
		}
	}
	
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	
}
