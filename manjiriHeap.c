#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define MaxHeap ADT
typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

/// @brief Creates an empty max-heap of size 'capacity'
/// @param capacity - max size of heap
/// @return Pointer to MaxHeap
MaxHeap *initHeap(int capacity){
    MaxHeap * heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->array= (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size =0;
    return heap;
}

int swap(int * a,int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

// Delete and free the max-heap structure
void destroyHeap(MaxHeap* heap){
    free(heap->array);
    free(heap);
}

/// @brief This restores the heap-order property for max-heap array at index 'i'
/// @param heap 
/// @param i - index of the max-heap array, which might potentialy be breaking the heap order
void heapify(MaxHeap* heap, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < heap->size && heap->array[left] > heap->array[largest]){
        largest = left;
    }
    if(right< heap->size && heap->array[right]>heap->array[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&heap->array[i],&heap->array[largest]);
        heapify(heap,largest);
    }
}

/// @brief This inserts a value into a max-heap
/// @param heap 
/// @param value 
void insert(MaxHeap* heap, int value){
  if(heap->size ==  heap->capacity){
    printf("Heap is full. Element %d cannot be inserted.\n", value);
    return;
  }

  int i = heap->size++;
  heap->array[i] = value; // value will be inserted at the end 
  while (i != 0 && heap->array[(i-1)/2] <heap->array[i]) //if the curr element is greater than the parent swap it
   {
    swap(&heap->array[i], &heap->array[(i-1)/2]);
    i = (i-1)/2;
  }
}


// displays the max element in the MaxHeap array
void peek_max(MaxHeap* heap){
    if(heap->size == 0){
        printf("The heap is empty");
    }
    printf("%d\t",heap->array[0]);
}

// extracts the max element from the MaxHeap array
int extractMax(MaxHeap* heap){
     if(heap->size == 0){
        printf("The heap is empty");
        return -1;
    }

    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return max;
}

/// @brief - Display the given MaxHeap in a visually clear way.
/// @param heap 
/// @param stop_idx - This index in the MaxHeap array corresponds to the last item of the heap
void display_heap(MaxHeap* heap, int stop_idx){
      printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}



/// @brief Build max-heap using the Floyd's method. This method should call initHeap
/// @param heap 
MaxHeap *constructHeap(int *arr, int arr_length);


// Sorts the given MaxHeap array in ascending order. 
// Post running this function, heap->array should contain the elements in the sorted order
// NOTE: This function should not use any additional data structures
void heapSort_ascending(MaxHeap* heap){

}

 int main()
{

    MaxHeap* heap = initHeap(10);
    insert(heap, 35);
    insert(heap, 33);
    insert(heap, 42);
    insert(heap, 10);
    insert(heap, 14);
    insert(heap, 19);
    insert(heap, 27);
    insert(heap, 44);
    insert(heap, 26);
    insert(heap, 31);
    display_heap(heap,9);
    // Deleting the maximum element in the heap

    return 0;
}