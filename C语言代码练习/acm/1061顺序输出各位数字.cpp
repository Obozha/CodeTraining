#include<stdio.h>

int main() {
	int i,n,testn,count=0,base=1;;
	scanf("%d",&n);
	testn=n;
	
	while(testn>0) {
		testn=testn/10;
		count++;
	}	// ���λȨ

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

// �����ǸĽ��� 
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
//    while( temp > 9) //�õ����λλȨbase
//
//    {
//
//        temp /= 10; //�ӵ���λ
//
//        base *= 10; //λȨ����
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
//        printf("%d ", n/base); //������λ
//
//        n %= base;    //�ӵ����λ
//
//        base /= 10;    //λȨ����
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


