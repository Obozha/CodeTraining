#include<stdio.h>
int main(){
	enum color{
		red=1,green,blue
	};
	
	enum color fav_color;
	printf("��������ϲ������ɫ:��1.red��2.green��3��blue)��");
	scanf("%d",&fav_color);
	switch(fav_color){
		case red:
			printf("��ϲ������ɫ�Ǻ�ɫ");
			break;
		case green:
			printf("��ϲ������ɫ����ɫ");
			break;
		case blue:
			printf("��ϲ������ɫ����ɫ");
			break;
		default:
			printf("��û��ѡ����ϲ������ɫ");
	}
	 
}
 

