#include<stdio.h>

int main(){
	int x,y,z,n,m=0;
	scanf("%d",&n);
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			for(z=0;z<10;z++){
				if(x!=0&&y!=0){
					if(((x*100+y*10+z)+(y*100+z*10+z*1))==n){
						printf("%4d%4d%4d",x,y,z);
						m=1;	
					}
				}
				
			}
		}
	}
	
	if(m==0){
		printf("No Answer");
	}
} 
