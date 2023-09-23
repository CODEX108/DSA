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
using namespace std;

int main()
{
    // declaration
    int A[5];
    for (int i : A)
    {
        A[i] = i;
        printf("%d\t", i);
    }

    // declaration + initialization
    int B[5] = {2, 3, 4, 5, 6};
    return 0;
}