#include<stdio.h>
#include<math.h>

int main(){
	double x1,x2,y1,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	if(x1>=0&&x2>=0&&x1<=100&&x2<=100&&y1>=0&&y2>=0&&y1<=100&&y2<=100){
		printf("%.2lf",sqrt(pow((x1-x2),2)+pow((y1-y2),2)));
	}
}
