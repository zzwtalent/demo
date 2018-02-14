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

int main()  
{  
    Person person;  
    std::cout << sizeof(person) << std::endl;  
    int *p = (int*)&person;  
    for (int i = 0; i < sizeof(person) / sizeof(int); ++i, ++p)  
    {  
        std::cout << *p << std::endl;  
    }  
    return 0;  
}   
