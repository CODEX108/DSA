#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define n 3

using namespace std;


struct Rectangle
{
    int length;
    int breadth;
    int arr[5];
};

//this(call by ref)  works same as call by value but different object is not created in the heap
// int area(struct Rectangle &r1){
//     r1.length = 50;
//     cout<<r1.breadth<<" "<<r1.length<<endl;
//     return (r1.length*r1.breadth);
// }

//call by address
int changeLength(struct Rectangle *p,int l){
    p->length = l;
}

//returning a pointer of type structure
//here fnction 'func' has created the strct inside the heap 
struct Rectangle *func(){
    struct Rectangle *p;
    p=(struct Rectangle *)malloc(sizeof( struct Rectangle)); //dynamic memory allocation for rectangle
    p->length=7;
    p->breadth=15;
    p[0].arr[0] = 20;
    return p;
}

struct body
{
    double p[3]; // Position
    double v[3]; // Velocity
    double a[3]; // Acceleration
    double radius;
    double mass;
};


int main()
{


    struct Rectangle *ptr = func();
    cout<<"Length "<<ptr->length<<" Breadth "<<ptr->breadth<<" Array element 1: "<<ptr[0].arr[0];
    
    
    struct body bodies[n];
    int a, b;
    for(a = 0; a < n; a++)
    {
        for(b = 0; b < 3; b++)
        {
            bodies[a].p[b] = 0;
            bodies[a].v[b] = 0;
            bodies[a].a[b] = 0;
        }
        bodies[a].mass = 0;
        bodies[a].radius = 1.0;
    }

    // struct Rectangle r1 = {10, 4};
    // cout << "Area of rectangle is : "<<area(r1)<<" "<<r1.breadth<<" "<<r1.length<<endl;
    // cout<<r1.breadth<<" "<<r1.length;

    // changeLength(&r1,20);
    // struct Rectangle *p = &r;
    /*
    Access the member from the structure using pointer: *p.length =20;
    but this wil throw error as '.' has higher precedense so (*p).length=20; works
    but this is quite lengthy the alternative for this is the  '->' symbol
    So for accessing element with normal var use . opr
    So for accessing element with pointer var use -> opr

    */
    // r.length = 40;
    // p->breadth = 20;

    // create an object dynamically using ptr
    // struct Rectangle *ptr;
    // ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    // ptr->length = 35;
    // ptr->breadth = 54;
    // cout<<ptr->breadth<<endl;


    return 0;
}