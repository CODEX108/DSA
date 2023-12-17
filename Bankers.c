/*
 * File: queue.c
 * Author: Manjiri Chavande
 * Email: cmanjiri1912@gmail.com
 * Created: September 12, 2023
 * Description: Implement a banker's queue. This uses 2 stacks to implement all the operations of a regular queue
 */

#include <stdio.h>
#include <stdlib.h>
#include "stacks.c"

// Queue implementation using two stacks
struct Queue
{
    struct Stack *stack1; // For enqueue
    struct Stack *stack2; // For dequeue
};

struct Queue *initialize_queue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->stack1 = initialize_stack(size);
    queue->stack2 = initialize_stack(size);
    return queue;
}

void enqueue(struct Queue *queue, char item)
{
    while (!isEmpty_stack(queue->stack2))
    {
        char temp = pop(queue->stack2);
        push(queue->stack1, temp);
    }
     push(queue->stack1, item);
      printf("Enqueued element: %c\n", item);
}

char dequeue(struct Queue *queue)
{
    while (!isEmpty_stack(queue->stack1))
    {
        char temp = pop(queue->stack1);
        push(queue->stack2, temp);
    }
    if (isEmpty_stack(queue->stack2))
    {
        printf("Queue Underflow\n");
        return '\0'; // Return null character for empty queue
    }
    return pop(queue->stack2);
}

int isEmpty(struct Queue *queue)
{
    return isEmpty_stack(queue->stack1) && isEmpty_stack(queue->stack2);
}

int isFull(struct Queue *queue)
{
    return isFull_stack(queue->stack1) && isFull_stack(queue->stack2);
}

void display(struct Queue *queue)
{
    printf("Queue elements: ");
    struct Stack *tempStack = initialize_stack(queue->stack1->size);

    // First, move all elements from stack1 to tempStack
    while (!isEmpty_stack(queue->stack1))
    {
        char temp = pop(queue->stack1);
        push(tempStack, temp);
    }

    // Then, move all elements from tempStack to stack1 and print them
    while (!isEmpty_stack(tempStack))
    {
        char temp = pop(tempStack);
        push(queue->stack1, temp);
        printf("%c ", temp);
    }

    printf("\n");
    free(tempStack); // Free the temporary stack
}


int main()
{
    struct Queue *queue = initialize_queue(10);

    enqueue(queue, 'A');
    enqueue(queue, 'B');
    enqueue(queue, 'C');
    display(queue);
    printf("Dequeued element: %c\n", dequeue(queue));
    printf("Dequeued element: %c\n", dequeue(queue));

    enqueue(queue, 'D');
    enqueue(queue, 'E');
    display(queue);

    printf("Dequeued element: %c\n", dequeue(queue));

    return 0;
}

