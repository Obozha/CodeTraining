#include<stdio.h>

int max_value(int array[][4]);

int main(){
	
	int a[3][4] = {{1,3,5,7},{2,4,6,8},{15,17,34,12}};
	printf("Max value is %d\n",max_value(a));
	return 0;
}

// �����ȫ��Ԫ�ض�����ֵ ���ṩȫ������ ���������ά���Բ�ָ�������ڶ�ά�ȵĳ��Ȳ���ʡ�� 
int max_value(int array[][4]){
	 
	 printf("sizeof(array):%d\n",sizeof(array));
	 printf("sizeof(array[0][0]):%d\n",sizeof(array[0][0]));
	 
	 int i,j,max,x,y;
	 max=array[0][0];
	 
	 for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(array[i][j]>max){
				max=array[i][j];; // �����ֵ����max
				x=i;
				y=j;
			}
	printf("Maxλ��Ϊ:��:%d,��:%d\n",x+1,y+1);
	return max;
}
