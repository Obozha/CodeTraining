#include<stdio.h>

int main() {
	int i,n,testn,count=0,base=1;;
	scanf("%d",&n);
	testn=n;
	
	while(testn>0) {
		testn=testn/10;
		count++;
	}	// 算出位权

//	printf("%d\n",count);
	
	for(i=1; i<count; i++) {
		base*=10;
//		printf("%d\n",base);		
	}
//	printf("%d\n",base);

	while(base>0){
		printf("%d ",n/base);
		n%=base;
		base/=10;
	}
	
}

// 以下是改进版 
//#include<stdio.h>
//
// 
//
//int main()
//
//{
//
//    int n, temp, base;
//
// 
//
//    scanf("%d", &n);
//
//    temp = n;
//
//    base = 1;
//
// 
//
//    while( temp > 9) //得到最高位位权base
//
//    {
//
//        temp /= 10; //扔掉各位
//
//        base *= 10; //位权增加
//
//    }
//
// 
//
//    while(base > 0) 
//
//    {
//
// 
//
//        printf("%d ", n/base); //输出最高位
//
//        n %= base;    //扔掉最高位
//
//        base /= 10;    //位权降低
//
//    }
//
// 
//
//    printf("\n");
//
//    return 0;
//
//}


