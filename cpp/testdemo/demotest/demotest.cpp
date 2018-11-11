#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

static void before(void) __attribute__ ((constructor));

static void after(void) __attribute__ ((destructor));

static void before()

{

	        fprintf(stderr, "In %s %d\n", __func__, __LINE__);

}

static void after()

{

	        fprintf(stderr, "In %s %d\n", __func__, __LINE__);

}


template<typename dst_type,typename src_type>
dst_type union_cast(src_type src)
{
	    union{
			        src_type s;
					        dst_type d;
							    }u;
		    u.s = src;
			    return u.d;
}

class Base {
	public:
		    virtual void f() { cout << "Base::f()" << endl; }
			    virtual void g() { cout << "Base::g()" << endl; }
				    virtual void h() { cout << "Base::h()" << endl; }
};

class Derive: public Base {
	    virtual void f() { cout << "Derive::f()" << endl; }
		    virtual void g1() { cout << "Derive::g1()" << endl; }
			    virtual void h1() { cout << "Derive::h1()" << endl; }
};

int main(int argc, char* argv[])
{
	cout<< "===============string compare begin==============!" << endl;
	char str1[] = "abc";
	char str2[] = "abc";
	const char str3[] = "abc";
	const char str4[] = "abc";
	const char *str5 = "abc";
	const char *str6 = "abc";
	char *str7 = "abc";
	char *str8 = "abc";
	cout << ( str1 == str2 ) << endl;
	cout << ( str3 == str4 ) << endl; 
	cout << ( str5 == str6 ) << endl;
	cout << ( str7 == str8 ) << endl;
	cout<< "===============string compare end==============!" << endl;

	cout<< "===============math test begin==============!" << endl;
	int a = 20;
	unsigned int b = (a>>2 + a&0x2);
	unsigned int c = (a>>1 + a&0x2);
	cout << "0x" << hex << a << endl;
	cout << "0x" << hex << (a>>2) << endl;
	cout << "0x" << hex << (a&0x2) << endl;
	cout << "0x" << hex << (a>>2 + a&0x2) << endl;
	cout << "0x" << hex << ((a>>2) + (a&0x2)) << endl;
	cout << "0x" << hex << c << endl;
	cout<< "===============math test end==============!" << endl;

	cout<< "===============Derive test end==============!" << endl;
    Base *base = new Derive();
    base->f();
	cout << "Base.addr=" << hex << &Base::f <<endl;
	cout << "Derive.addr="<< hex << &Derive::g <<endl;
	void* p2 = union_cast<void*>(&Base::g);
	cout<<p2<<endl;
	cout<< "===============Derive test end==============!" << endl;
}
