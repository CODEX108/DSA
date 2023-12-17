#include <stdio.h>
#include<stdlib.h>
#include <limits.h>

// A C program to demonstrate implementation
// of k queues in a single array in time and space efficient way
struct kQueues
{
    int *arr;
    int *front;
    int *rear;
    int *next;// Array of size n to store next 
    // entry in all queues
    int n, k;
    int free;
};

// Constructor to create k queues
// in an array of size n
struct kQueues *create(int k1, int n1)
{
    struct kQueues *ks = (struct kQueues *)malloc(sizeof(struct kQueues));

    ks->k = k1;
    ks->n = n1;
    ks->arr = (int *)malloc(n1 * sizeof(int));
    ks->front = (int *)malloc(k1 * sizeof(int));
    ks->rear = (int *)malloc(k1 * sizeof(int));
    ks->next = (int *)malloc(n1 * sizeof(int));

    // Initialize all queues as empty
    for (int i = 0; i < k1; i++)
        ks->front[i] = -1;

    // Initialize all spaces as free
    ks->free = 0;
    for (int i = 0; i < n1 - 1; i++)
        ks->next[i] = i + 1;
    ks->next[n1 - 1] = -1; // -1 is used to indicate the end of the free list

    return ks;
}

// A utility function to check if there is space available
int isFull(struct kQueues *ks)
{
    return (ks->free == -1);
}

// To enqueue an item in queue number
// 'qn' where qn is from 0 to k-1
void enqueue(struct kQueues *ks, int item, int qn)
{
    // Overflow check
    if (isFull(ks))
    {
        printf("\nQueue Overflow\n");
        return;
    }

    int i = ks->free; // Store index of the first free slot

    // Update the index of the free slot to the index of the next slot in the free list
    ks->free = ks->next[i];

    if (ks->front[qn] == -1)
        ks->front[qn] = i;
    else
        ks->next[ks->rear[qn]] = i;

    ks->next[i] = -1;

    // Update next of rear and then rear for queue number 'qn'
    ks->rear[qn] = i;

    // Put the item in the array
    ks->arr[i] = item;
}

// To dequeue an item from queue number 'qn' where qn is from 0 to k-1
int dequeue(struct kQueues *ks, int qn)
{
    // Underflow check
    if (ks->front[qn] == -1)
    {
        printf("\nQueue Underflow\n");
        return INT_MAX;
    }

    // Find the index of the front item in queue number 'qn'
    int i = ks->front[qn];

    // Change front to store the next of the previous front
    ks->front[qn] = ks->next[i];

    // Attach the previous front to the beginning of the free list
    ks->next[i] = ks->free;
    ks->free = i;

    // Return the previous front item
    return ks->arr[i];
}


void displayQueue(struct kQueues *ks, int qn)
{
    printf("Contents of Queue %d: ", qn);
    int i = ks->front[qn];
    while (i != -1)
    {
        printf("%d ", ks->arr[i]);
        i = ks->next[i];
    }
    printf("\n");
}
 void displayAll(struct kQueues *ks)
{
    printf("Contents of all queues: ");

    for (int qn = 0; qn < ks->n; ++qn)
    {
        if (ks->front[qn] != -1)
        {
            int i = ks->front[qn];
            while (i != -1)
            {
                printf("%d ", ks->arr[i]);
                i = ks->next[i];
            }
        }
    }

    printf("\n");
}

/* Driver program to test kStacks class */
int main()
{
    // Let us create 3 queues in an array of size 10
    int k = 3, n = 10;
    struct kQueues *ks = create(k, n);

    // Let us put some items in queue number 2
    enqueue(ks, 15, 2);
    enqueue(ks, 45, 2);

    // Let us put some items in queue number 1
    enqueue(ks, 17, 1);
    enqueue(ks, 49, 1);
    enqueue(ks, 39, 1);

    // Let us put some items in queue number 0
    enqueue(ks, 11, 0);
    enqueue(ks, 9, 0);
    enqueue(ks, 7, 0);

    
   
    displayQueue(ks, 2);
    displayQueue(ks, 1);
    displayQueue(ks, 0);
     displayAll(ks);
    return 0;
}
