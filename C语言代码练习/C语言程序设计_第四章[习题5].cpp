#include<stdio.h>
#include<math.h>

int main(){
	int input;
	
	
	while(1){
		printf("请输入小于1000的正数:");
		scanf("%d",&input);
		if(input<1000&&input>0){
			
			printf("平方根:%d\n",(int)sqrt(input));
			//fflush(stdout);
		}else{
			printf("Error!,");
			continue;
		}
	}


	
}
