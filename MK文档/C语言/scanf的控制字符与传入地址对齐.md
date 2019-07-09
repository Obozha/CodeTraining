##scanf的控制字符与传入地址对齐


```
#include<stdio.h>

int main(){
	char a,b,c;
	scanf("%c %c %c",&a,&b,&c);
    // 这里是用值放入对应每个地址 而地址是有数据类型的

	int max =a;
	if(b>max){
		max=b;
	}
	if(c>max){
		max=c;
	}
	printf("%c",max);
	return 0;
}
```