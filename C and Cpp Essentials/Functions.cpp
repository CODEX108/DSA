#include <stdio.h>
#include <iostream>
using namespace std;

//Call by address
int swap(int &x,int &y){
    int temp;
    temp = x;
    x=y;
    y= temp;
}

int main()
{
    int num1=10;int num2=20;
    swap(num1,num2);
    cout<<"First Number: "<<num1<<endl;
    cout<<"Second Nuber: "<<num2<<endl;
    
   return 0;
}
