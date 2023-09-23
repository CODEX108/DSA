#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r = {10, 4};
    struct Rectangle *p = &r;
    /*
    Access the member from the structure using pointer: *p.length =20;
    but this wil throw error as '.' has higher precedense so (*p).length=20; works
    but this is quite lengthy the alternative for this is the  '->' symbol
    So for accessing element with normal var use . opr
    So for accessing element with pointer var use -> opr

    */
    r.length = 40;
    p->breadth = 20;

    // create an object dynamically using ptr
    struct Rectangle *ptr;
    ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    ptr->length = 35;
    ptr->breadth = 54;
    cout<<ptr->breadth<<endl;
    return 0;
}