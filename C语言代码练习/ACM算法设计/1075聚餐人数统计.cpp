#include<stdio.h>

int main(){
	int man,girl,baby,count,cost;
	int mode=0;
	scanf("%d %d",&count,&cost);
	
	for(man=0;man<=count;man++){
		for(girl=0;girl<=count;girl++){
			for(baby=0;baby<=count;baby++){
				if(((man*3+girl*2+baby*1)==cost)&&(man+girl+baby==30)){
					printf("%d %d %d\n",man,girl,baby);
					mode=1;
				}
			}
		}
	}
	
	if(mode==0){
		printf("No answer");
	}
	return 0;
}
