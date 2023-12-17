
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    char *array;
};

struct Stack *initialize_stack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (char *)malloc(size * sizeof(char));
    return stack;
}

int isFull_stack(struct Stack *stack)
{
    return stack->top == stack->size - 1;
}

int isEmpty_stack(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char item)
{
    if (isFull_stack(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
     stack->array[++stack->top] = item;
         printf("Pushed element: %c\n", item);
}

char pop(struct Stack *stack)
{
    if (isEmpty_stack(stack))
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack->array[stack->top--];
}

void display(struct Stack *stack)
{
    if (isEmpty_stack(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: \n");
        for (int i = stack->top; i >= 0; i--)
        {
            printf("%c \n", stack->array[i]);
        }
        printf("\n");
    }
}

void peek(struct Stack *stack)
{
    if (isEmpty_stack(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %c\n", stack->array[stack->top]);
    }
}

int main()
{
    int size = 5;
    struct Stack *stack = initialize_stack(size);

    push(stack, '2');
    push(stack, '1');
    push(stack, '3');
    push(stack, '4');
    push(stack, '5');

    display(stack);

    printf("Peek: ");
    peek(stack);

    printf("Popped element: %c\n", pop(stack));
    printf("Popped element: %c\n", pop(stack));
    printf("Popped element: %c\n", pop(stack));
    printf("Popped element: %c\n", pop(stack));
    printf("Popped element: %c\n", pop(stack));
    printf("Popped element: %c\n", pop(stack));


    printf("Peek: ");
    peek(stack);
    return 0;
}
