/*
Collection of similar elements stored in contigeous memory locations is known as an array
The main memory is divided into 3 sections
    - Heap
    - Stacks (Local and Global)
        -> The array will be created inside the stack
    - Code section
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0 ;i<n;++i ){
        cout<<arr[i]<<" ";
        }
}

//returning array from a function
int * fun(int sz){
    int *p;
    p = (int *)malloc(sizeof(int));
    for(int i=0;i<=sz;i++)
    p[i] = i+1;

    return p;
}

int main()
{
    // declaration
    // int A[5];
    // for (int i : A)
    // {
    //     A[i] = i;
    //     printf("%d\t", i);
    // }

    // // declaration + initialization
    // int B[5] = {2, 3, 4, 5, 6};

    int arr[3] = {2,4,5};
    display(arr,3);

    int size = 6;
    int *res = fun(size);
    for (int i = 0; i <= size; i++)
    {
        cout<<res[i]<<endl;
    }
    
    
    return 0;
}