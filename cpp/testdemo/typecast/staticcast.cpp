#include<stdio.h>
#include<stdlib.h>
#include<iostream>

class Base{
public:
	Base():x(1){}
	virtual ~Base(){}
	virtual void fun1(){}
public:
	int x;
};

class Derived:public Base{
public:
	Derived():y(2){}
public:
	int y;
};

int main(int argc, char* argv[])
{
	printf("begin static_cast1:\n");
	Base *p1 = new Derived();
	Derived * dpt1 = static_cast<Derived *>(p1);
	if(dpt1 != NULL)
	{
		printf("after static_cast1:x[%d],y[%d]\n",dpt1->x,dpt1->y);
	}
	printf("begin static_cast2:\n");
	Base *p2 = new Base();
	Derived * dpt2 = static_cast<Derived *>(p2);
	if(dpt2 != NULL)
	{
		printf("after static_cast2:x[%d],y[%d]\n",dpt2->x,dpt2->y);
	}
	printf("end\n");
}
