#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap *initHeap(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->array = (int *)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void destroyHeap(MaxHeap *heap) {
    free(heap->array);
    free(heap);
}

void heapify(MaxHeap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i) {
        // Swap heap->array[i] and heap->array[largest]
        int temp = heap->array[i];
        heap->array[i] = heap->array[largest];
        heap->array[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(heap, largest);
    }
}

void insert(MaxHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow: Cannot insert more elements.\n");
        return;
    }

    // Insert the new key at the end
    int i = heap->size;
    heap->array[i] = value;
    heap->size++;

    // Fix the max heap property if it is violated
    while (i > 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        // Swap heap->array[i] and heap->array[(i-1)/2]
        int temp = heap->array[i];
        heap->array[i] = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = temp;

        // Move to the parent index
        i = (i - 1) / 2;
    }
}

void peek_max(MaxHeap *heap) {
    if (heap->size > 0) {
        printf("Max Element: %d\n", heap->array[0]);
    } else {
        printf("Heap is empty.\n");
    }
}

int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty. Returning INT_MIN.\n");
        return INT_MIN;
    }
    
    // Store the root (maximum element)
    int root = heap->array[0];

    // Replace the root with the last element
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    // Heapify the root to maintain the max-heap property
    heapify(heap, 0);

    return root;
}

void display_heap(MaxHeap *heap, int stop_idx) {
    printf("Max Heap: ");
    for (int i = 0; i <= stop_idx; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

MaxHeap *constructHeap(int *arr, int arr_length) {
    MaxHeap *heap = initHeap(arr_length);
    heap->size = arr_length;

    for (int i = 0; i < arr_length; i++) {
        heap->array[i] = arr[i];
    }

    for (int i = (arr_length - 1) / 2; i >= 0; i--) {
        heapify(heap, i);
    }

    return heap;
}

void heapSort_ascending(MaxHeap *heap) {
    for (int i = heap->size - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        int temp = heap->array[0];
        heap->array[0] = heap->array[i];
        heap->array[i] = temp;

        // Reduce the heap size and heapify the root
        heap->size--;
        heapify(heap, 0);
    }
}

int main() {
    // Example Usage
    MaxHeap *maxHeap = initHeap(10);
    insert(maxHeap, 4);
    insert(maxHeap, 10);
    insert(maxHeap, 8);
    insert(maxHeap, 5);
    insert(maxHeap, 1);

    printf("Max Heap after insertions:\n");
    display_heap(maxHeap, maxHeap->size - 1);

    peek_max(maxHeap);

    int extracted = extractMax(maxHeap);
    printf("Extracted Max Element: %d\n", extracted);

    printf("Max Heap after extraction:\n");
    display_heap(maxHeap, maxHeap->size - 1);

    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    MaxHeap *constructedHeap = constructHeap(arr, arr_length);

    printf("Max Heap constructed using array:\n");
    display_heap(constructedHeap, constructedHeap->size - 1);

    heapSort_ascending(constructedHeap);

    printf("Sorted array using Heap Sort (ascending order):\n");
    display_heap(constructedHeap, constructedHeap->size - 1);

    destroyHeap(maxHeap);
    destroyHeap(constructedHeap);

    return 0;
}
