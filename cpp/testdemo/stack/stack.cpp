#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

int a=0; //在数据段
char *p1; //在BSS段
int main()
{
	int b;//栈
	char s[] ="abc";//栈
	char *p2;//栈
	char *p3 = "123456";//在常量区，p3在栈
	static int c = 0;//在数据段
	p1 = (char *)malloc(10);
	p2 = (char *)malloc(20);
	//在堆
	strcpy(p1,"123456");//123456/0存放在常量区，编译器将它与p3指向的"123456"优化为一个地方

	printf("end\n");
}
