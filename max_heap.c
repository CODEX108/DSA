// Create a max-heap ADT using array and implement various operations
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Define MaxHeap ADT
typedef struct
{
    int *array;
    int size;
    int capacity;
} MaxHeap;
// Creates an empty max-heap of size 'capacity'
MaxHeap *initHeap(int capacity)
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->array = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}
// Delete and free the max-heap structure
void destroyHeap(MaxHeap *heap)
{
    free(heap->array);
    free(heap);
}
// Restores the heap-order property for max-heap array atindex 'i'
void heapify(MaxHeap *heap, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < heap->size && heap->array[leftChild] >
                                      heap->array[largest])
        largest = leftChild;
    if (rightChild < heap->size && heap->array[rightChild] > heap->array[largest])
        largest = rightChild;
    if (largest != i)
    {
        int temp = heap->array[i];
        heap->array[i] = heap->array[largest];
        heap->array[largest] = temp;
        heapify(heap, largest);
    }
}
// Inserts a value into a max-heap
void insert(MaxHeap *heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap overflow\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;
    while (i > 0 && heap->array[(i - 1) / 2] < heap->array[i])
    {
        int temp = heap->array[i];
        heap->array[i] = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}


// Displays the max element in the MaxHeap array
void peek_max(MaxHeap *heap)
{
    if (heap->size > 0)
    {
        printf("Max Element: %d\n", heap->array[0]);
    }
    else
    {
        printf("Heap is empty\n");
    }
}
// Extracts the max element from the MaxHeap array
int extractMax(MaxHeap *heap)
{
    if (heap->size == 0)
    {
        printf("Heap underflow\n");
        return -1; // indicating failure
    }
    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return max;
}
// Display the given MaxHeap in a visually clear way
void display_heap(MaxHeap *heap, int stop_idx)
{
    for (int i = 0; i <= stop_idx; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}
// Build max-heap using the Floyd's method
MaxHeap *constructHeap(int *arr, int arr_length)
{
    MaxHeap *heap = initHeap(arr_length);
    for (int i = 0; i < arr_length; i++)
    {
        heap->array[i] = arr[i];
    }
    heap->size = arr_length;
    for (int i = arr_length / 2 - 1; i >= 0; i--)
    {
        heapify(heap, i);
    }
    return heap;
}
// Sorts the given MaxHeap array in ascending order
void heapSort_ascending(MaxHeap *heap)
{
    for (int i = heap->size - 1; i > 0; i--)
    {
        int temp = heap->array[0];
        heap->array[0] = heap->array[i];
        heap->array[i] = temp;
        heap->size--;
        heapify(heap, 0);
    }
}
int main()
{
    int arr[] = {28, 92, 13, 2, 19, 10, 28};
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    MaxHeap *heap = constructHeap(arr, arr_length);
    printf("Max-Heap: ");
    display_heap(heap, heap->size - 1);
    peek_max(heap);
    int extractedMax = extractMax(heap);
    printf("Extracted Max Node from Max Heap: %d\n",
           extractedMax);
    printf("Heap after extraction is as follows: ");
    display_heap(heap, heap->size - 1);
    heapSort_ascending(heap);
    printf("Sorted Array is as follows: ");
    display_heap(heap, arr_length - 1);
    destroyHeap(heap);
    return 0;
}
