#include<stdio.h>

void copy_string(char*,char*);
int main() {
	char *a="I am a teacher";			// a��char*��ָ�����
	char b[]="You are a student.";		// b���ַ�����
	char *p=b;							// ʹָ�����pָ��b������Ԫ��
	printf("string a=%s\nstring b=%s\n",a,b);	// ���a����b��
	printf("\ncopy string a to string b:\n");
	copy_string(a,p);							// ����copy_string���� ʵ��Ϊָ�����
	printf("string a=%s\nstring b=%s\n",a,b);	// ����ı���a����b��
	return 0;
}

void copy_string1(char * from,char * to) { 	// ���庯�����β�Ϊ�ַ�ָ�����
	for(; *from!='\0'; from++,to++) {
		*to=*from;
	}
	*to='\0';
}

void copy_string2(char * from,char * to) {
	while((*to=*from)!='\0') {
		to++;
		from++;
	}
}

void copy_string3(char * from,char * to) {
	while((*to++=*from++)!='\0');
}

void copy_string4(char * from,char * to) {
	while(*from!='\0')
		*to++=*from++;
	*to='\0';
}

void copy_string5(char * from,char * to) {
	while(*from)
		*to++=*from++;
	*to='\0';
}

void copy_string6(char * from,char * to) {
	while(*to++=*from++);
}

void copy_string7(char * from,char * to){
	for(;*to++=*from++;);	
}

void copy_string8(char * from,char * to){
	for(;(*to++=*from++)!=0;);	
}

void copy_string(char from[],char to[]){
	char *p1,*p2;
	p1=from;
	p2=to;
	while((*p2++=*p1++)!='\0');
}



