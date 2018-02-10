#include <iostream>
#include <stdio.h>

using namespace std;
int main(int argc, char* argv[])
{
	cout<< "input arguments:" << endl;
	for(int i=0; i<argc; i++)
	{
		printf("arg[%d]=[%s]\n", i, argv[i]);
	}

	cout<< "=====end=====" << endl;
}
