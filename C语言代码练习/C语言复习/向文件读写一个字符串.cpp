#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fp;
	char str[3][10],temp[10];
	// str����������ַ����Ķ�ά���飬temp����ʱ����
	int i,j,k,n=3;
	printf("Enter string:\n"); //��ʾ�����ַ���
	for(i=0;i<n;i++) 
		gets(str[i]); // �����ַ���
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(strcmp(str[k],str[j])>0){
				// strcmp s1==s2 0 s1<s2 С��0 s1>s2 ����0 
				k=j;
			}
		}
		if(k!=j){
			strcpy(temp,str[i]);
			strcpy(str[i],str[k]);
			strcpy(str[k],temp);
		}
	}
	if((fp=fopen("D:\\a\\string.dat","w"))==NULL){
		printf("can't open file!\n");
		exit(0);
	}
 	printf("\nThe new sequence:\n");
 	for(i=0;i<n;i++){
 		fputs(str[i],fp);
 		fputs("\n",fp);
 		// ������ļ�дһ���ַ�����Ȼ�����һ�����з� 
 		printf("%s\n",str[i]); //����Ļ����ʾ 
	}
	return 0;
}
