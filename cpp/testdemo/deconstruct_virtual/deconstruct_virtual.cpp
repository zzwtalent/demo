#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using std::cout;
using std::endl;

class Base
{
public:
Base()
{
        cout << "Base construct" << endl; //begin
}
virtual ~Base()
{
        cout << "Base deconstruct" << endl; //begin
}
// ClassID 返回一个class相关的ID号
virtual int GetID() { return 1;}
};


class Derived: public Base
{
public:
Derived()
{
        cout << "Derived construct" << endl; //begin
}

~Derived()
{
        cout << "Derived deconstruct" << endl; //begin
}

int GetID() { return 2;}
};


int main()
{
Derived objDerived;
Base objBase = objDerived;
cout << "begin" << endl; //begin
cout << objBase.GetID()<< endl; // 打印出1，不是2！
cout << "end" << endl; //end
return 0;

}
