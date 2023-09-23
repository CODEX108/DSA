/*
Refernce is an alias/nickname given to a function
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    //a and r point to the same address
    int a= 10;
    int &r = a;
    int b = 30;
    r=b;
    cout<<a<<endl;
    cout<<r<<endl;
    return 0;
}