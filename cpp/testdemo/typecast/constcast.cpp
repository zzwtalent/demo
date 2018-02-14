#include<stdio.h>
#include<stdlib.h>
#include<iostream>


int main(int argc, char* argv[])
{
	printf("begin static_cast1:\n");
	const char* str = "helloworld";
	char* vstr = const_cast<char *>(str);
	printf("after const_cast1:str[%s]\n",vstr);
	printf("end\n");
}
