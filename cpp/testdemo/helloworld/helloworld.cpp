#include <iostream>

using namespace std;
class CTest  
{  
	    int b;  
	public:  
		    CTest() : b(0){};  
			    ~CTest(){};  
				  
				    const int Cal(int &a) const;  
};  
  
const int CTest::Cal(int &a) const  
{  
		int c = a+1;
		    return c;
}  

int main(int argc, char* argv[])
{
	cout<< "hello world!!" << endl;
	CTest oTest;
	int i = 2;
	cout<<"Cal(2)="<<oTest.Cal(i)<<endl;
}
