#include<stdio.h>
#include<stdlib.h>

class A
{
public:
    int a;
};
class B : virtual public A
{
public:
   int b;
};
class C :virtual public A
{
public:
   int c; 
};
class D : public B, public C
{
public:
   int d;
};

int main(int argc, char * argv[])
{
	printf("begin\n");
	printf("sizeod(A)=(%lu)\n",sizeof(A));
	printf("sizeod(B)=(%lu)\n",sizeof(B));
	printf("sizeod(C)=(%lu)\n",sizeof(C));
	printf("sizeod(D)=(%lu)\n",sizeof(D));
	printf("end\n");
}
