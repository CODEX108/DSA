#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
/*
Uses Of Pointers
    - Accessing Heap
    -Accessing resources
    - Parameter passing
*/
int main()
{
    int a = 10;
    int *p;
    p = &a;
    printf("dereferencing the pointer : %d\n", *p);
    printf("%d %d", p, &a);
    // pointer to an array
    int A[5] = {2, 4, 6, 8, 10};
    int *s;
    s = A; // becase the starting address of the array is its name itself
    for (int i = 0; i < 5; i++)
    {
        cout << s[i] << endl;
    }

    // array created in heap
    int *add;
    add = (int *)malloc(2 * sizeof(int));
    add[0] = 23, add[1] = 90;
    for (int i = 0; i < 2; i++)
    {
        cout << add[i] << endl;
    }

    free(p);
    free(add);
    return 0;
}