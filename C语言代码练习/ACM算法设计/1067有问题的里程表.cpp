#include<stdio.h>

int main(){
	int num,i,j,icount=0,rcount=0,test=0,base=1,havef=0;
	scanf("%d",&num);
	for(i=1;i<=num;i++){
		test=i;
		while(test>0) {
			test=test/10;
			icount++;
		}	// ���λȨ
	
		for(j=1; j<icount; j++) {
			base*=10;  // ������� 
		}
		
		test=i; // �����ٴ���Ҫtest���¸�ֵ��Ϊ�˲�Ӱ��i 
		
		while(base>0){
//			printf("%d ",test/base);
			if((test/base)==4){		// ���λ������4��������ȥ 
				havef=1;
//				printf("*");
			}
			test%=base;
			base/=10;
		}
		
		if(havef==0){	// �ж�ѭ�����Ƿ���4 
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
