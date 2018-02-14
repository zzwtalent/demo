#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using std::cout;
using std::endl;

class Base
{
private:
int m_nID;
public:
Base()
{
m_nID = ClassID();
}
// ClassID 返回一个class相关的ID号
virtual int ClassID() { return 1;}
int GetID() { return m_nID; }
};


class Derived: public Base
{
public:
Derived()
{
}

virtual int ClassID() { return 2;}
};


int main()
{
Derived cDerived;
cout << "begin" << endl; //begin
cout << cDerived.GetID()<< endl; // 打印出1，不是2！
cout << "end" << endl; //end
return 0;

}
