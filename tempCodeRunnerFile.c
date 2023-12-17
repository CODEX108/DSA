void insert(MaxHeap *heap, int value)
{
    int i = heap->size + 1;  // Assuming 1-based indexing
    int temp = value;
    int *arr = heap->array;

    // Ensure that the array has enough space for the new element
    if (i >= heap->capacity)
    {
        // Handle the case where the array is full; you may need to resize the array
        // or return an error.
        return;
    }

    while (i > 1 && temp > arr[i / 2])
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = temp;

    heap->size++;  // Update the size
}