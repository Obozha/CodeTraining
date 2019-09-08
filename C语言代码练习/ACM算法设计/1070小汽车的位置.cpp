#include<stdio.h>
int main() {
	int i=0,time=0,command=0,temp=0,interval=0;
	int north=1,south=2,west=3,east=4;
	int initdirection=north;
	int x=0,y=0;
	int initspeed=10;

	while(command!=3) {
		temp=time;
		scanf("%d %d",&time,&command);
		switch(command) { // command=1 ×ó command=2 ÓÒ
			case 1:
				if(initdirection==north) {
					interval=time-temp;
					y=y+interval*initspeed;
					initdirection=west;
				} else if(initdirection==south) {
					interval=time-temp;
					y=y-interval*initspeed;
					initdirection=east;
				} else if(initdirection==west) {
					interval=time-temp;
					x=x-interval*initspeed;
					initdirection=south;
				} else if(initdirection==east) {
					interval=time-temp;
					x=x+interval*initspeed;
					initdirection=north;
				}
				break;
			case 2:
				if(initdirection==north) {
					interval=time-temp;
					y=y+interval*initspeed;
					initdirection=east;
				} else if(initdirection==south) {
					interval=time-temp;
					y=y-interval*initspeed;
					initdirection=west;
				} else if(initdirection==west) {
					interval=time-temp;
					x=x-interval*initspeed;
					initdirection=north;
				} else if(initdirection==east) {
					interval=time-temp;
					x=x+interval*initspeed;
					initdirection=south;
				}
				break;
			case 3:
				if(initdirection==north) {
					interval=time-temp;
					y=y+interval*initspeed;
				} else if(initdirection==south) {
					interval=time-temp;
					y=y-interval*initspeed;
				} else if(initdirection==west) {
					interval=time-temp;
					x=x-interval*initspeed;
				} else if(initdirection==east) {
					interval=time-temp;
					x=x+interval*initspeed;
				}
				printf("%d %d",x,y);
				break;
		}
	}
}

