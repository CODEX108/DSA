#include <stdio.h>
#include <stdlib.h>
#define N 5
/*
5 | 70 | <- top
4 | 60 |
3 | 50 |
2 | 40 |
1 | 30 |
0 | 20 |
*/

int stack[N];
int top = -1;

void push()
{
    int x;
    printf("Enter the number you want to push\n");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        // increase the top
        stack[++top] = x;
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("The poped element is %d\n", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top of Stack: %d\n", stack[top]);
    }
}

void display()
{
    for (int i=top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("Enter the choice code\n 1.Push\t2.Pop\t3.Peek\t4.Display\t5.Exit\n=>");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Please select valid choice\n");
            break;
        }
    } while (choice != 5);
    return 0;
}