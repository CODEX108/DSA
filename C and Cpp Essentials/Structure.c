#include <stdio.h>

//definition
struct Rectangle
{
    int length;
    int breadth;
};

struct Cards
{
    int face;
    int shape;
    int color;
    char x;
};


int main(){
    struct Rectangle r;
    r.length = 20;
    r.breadth=15;

//declaration + initlaization
    struct Cards c = {1,0,0};
    // c.face = 1;
    // c.shape = 0;
    // c.color = 0;

 //Array of structures
 struct Cards Deck[52] = {{1,0,0},{3,2,2}};
 printf("%d ",Deck[0].face);

 printf("\n%d is the size of structure cards\n",sizeof(c));

 int *p1;
 float *p2;
 char *p3;
 double *p4;
 struct Rectangle *p5;
    printf("All pointers take the same amount of memory space");
    printf("%d\n",sizeof(p1));
    printf("%d\n",sizeof(p2));
    printf("%d\n",sizeof(p3));
    printf("%d\n",sizeof(p4));
    printf("%d\n",sizeof(p5));

    return 0;
}