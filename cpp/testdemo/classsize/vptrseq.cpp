#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class Person  
{  
    public:  
        Person():mId(0), mAge(20){ 
	//	++sCount; 
	}  
        static int personCount()  
        {  
            return sCount;  
        }  
  
        virtual void print()  
        {  
            std::cout << "id: " << mId  
                 << ", age: " << mAge << std::endl;  
        }  
        virtual void job()  
        {  
            std::cout << "Person" << std::endl;  
        }  
        virtual ~Person()  
        {  
         //   --sCount;  
            std::cout << "~Person" << std::endl;  
        }  

    protected:  
        static int sCount;  
        int mId;  
        int mAge;  
  
};  

typedef void (*FuncPtr)();  
int main()  
{  
    Person person;  
    int **vtbl = (int**)*(int**)&person;  
    for (int i = 0; i < 3 && *vtbl != NULL; ++i)  
    {  
        FuncPtr func = (FuncPtr)*vtbl;  
        func();  
        ++vtbl;  
    }  
  
    while (*vtbl)  
    {  
        std::cout << "*vtbl == " << *vtbl << std::endl;  
        ++vtbl;  
    }  
    return 0;  
}  
