#include<stdio.h>
#include<math.h>

int main(){
	int input;
	
	
	while(1){
		printf("������С��1000������:");
		scanf("%d",&input);
		if(input<1000&&input>0){
			
			printf("ƽ����:%d\n",(int)sqrt(input));
			//fflush(stdout);
		}else{
			printf("Error!,");
			continue;
		}
	}


	
}
