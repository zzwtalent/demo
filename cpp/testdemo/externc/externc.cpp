#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "testfunc.h"

class CTestClass{
public:
	void doCal(int a, int b)	
	{
		printf("a[%d]+b[%d]=[%d]\n", a, b, testfunc(a, b));
	}
};
int main(int argc,char * argv[])
{
	printf("begin\n");
	CTestClass* objTestClass = new CTestClass();
	objTestClass->doCal(1, 2);	
	printf("end\n");
}

