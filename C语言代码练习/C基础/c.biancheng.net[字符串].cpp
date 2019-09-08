#include<stdio.h>

int main(){
	// 用来存放字符的数组称为字符数组
	char a[10]; // 一维字符数组
	char b[5][10]; // 二维字符数组
	char c[20]={'c','.','p','r','o','g','r','a','m'}; // 给部分数组元素赋值
	char d[] = {'c','.','p','r','o','g','r','a','m'}; // 对全体元素赋值可以省去长度
	
	char str[30] = {"c.biancheng.net"};
	char str2[30] = "c.biancheng.net"; // 这种形式更加简洁，实际开发中常用
	// [Error] 'char str [30]' previously declared here
	// 为了方便，也可以不指定数组长度 从而写作
	char str3[] = {"HelloWorld"};
	char str4[] = "c.biancheng.net"; // 这种形式更加简洁 实际开发中常用 
	
	// [留意] 字符数组只有在定义时才能将整个字符串一次性地赋值给它 
	// 定义完了  就只能一个字符一个字符的赋值
	
	char str5[7];
	// str = "abc123" error 
	
	str5[0] = 'a';
	str5[1] = 'b';
	str5[2] = 'c';
	str5[3] = '1';
	str5[4] = '2';
	str5[5] = '3';
	
} 
