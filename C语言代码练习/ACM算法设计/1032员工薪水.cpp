#include<stdio.h>

int main() {
	int salesVolume;
	scanf("%d",&salesVolume);
	if(salesVolume>50000) {
		printf("%.2f",1500+(salesVolume-50000)*0.02+(50000-10000)*0.03+10000*0.05);
	} else if(salesVolume>10000) {
		printf("%.2f",1500+(salesVolume-10000)*0.03+10000*0.05);
	} else if(salesVolume<=10000) {
		printf("%.2f",1500+salesVolume*0.05);
	}
	return 0;
}
