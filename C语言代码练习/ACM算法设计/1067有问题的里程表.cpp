#include<stdio.h>

int main(){
	int num,i,j,icount=0,rcount=0,test=0,base=1,havef=0;
	scanf("%d",&num);
	for(i=1;i<=num;i++){
		test=i;
		while(test>0) {
			test=test/10;
			icount++;
		}	// 算出位权
	
		for(j=1; j<icount; j++) {
			base*=10;  // 算出除数 
		}
		
		test=i; // 这里再次需要test重新赋值，为了不影响i 
		
		while(base>0){
//			printf("%d ",test/base);
			if((test/base)==4){		// 如果位数中有4，就跳过去 
				havef=1;
//				printf("*");
			}
			test%=base;
			base/=10;
		}
		
		if(havef==0){	// 判断循环中是否有4 
			rcount++;
//			printf(" %d",rcount);
		}else{
			havef=0;
		}
		
		icount=0;
		base=1;
//		printf("\n");
	}
	printf("%d",rcount);
} 
