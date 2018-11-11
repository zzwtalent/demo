#include <iostream>

using namespace std;

#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <string>  
#include <cstring>  
using namespace std;  
  
struct node1 //这个node占了32个字节  
{  
	  
	    int a;  
	    float f;//a 和 f 一共占8个字节  
	    char c;//虽然c只有一个字节，但单独占了8个字节（需要内存对齐）  
	    double d;// 很显然，占8个字节  
	    struct node* next;//指针变量虽然4个字节，但也单独占8个字节  
						  
};  
struct node2 //这个node占了24个字节，比上一个node要节省内存  
{  
	    int a;  
	    float f;//a 和 f 一共占8个字节  
	    char c;  
	    struct node* next;//c和next 一共占用8个字节  
	    double d;//占用8个字节  
};  
  
typedef struct Goods1
{
	    char        a[18];//18
	    double      b;//8
	    char        c;//1
	    int         d;//4
	    short       e;//2
}Goods1;

typedef struct Goods2
{
	    char        a[18];//18
	    char        c;//1， 
	    double      b;//8       
	    int         d;//4
	    short       e;//2
}Goods2;

int main()  
{  
	    struct node1* p1;  
	    struct node1 anode1;  
	    struct node2* p2;  
	    struct node2 anode2;  
	    printf("%d %d\n",sizeof(p1),sizeof(anode1));  
	    printf("%d %d\n",sizeof(p2),sizeof(anode2));  



	    struct Goods1* g1;  
	    struct Goods1 agoods1;  
	    struct Goods2* g2;  
	    struct Goods2 agoods2;  
	    printf("%d %d\n",sizeof(g1),sizeof(agoods1));  
	    printf("%d %d\n",sizeof(g2),sizeof(agoods2));  
	    return 0;  
}  
