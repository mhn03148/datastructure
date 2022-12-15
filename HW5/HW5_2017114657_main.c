#include <stdio.h>
#include "HW5.h"

void heapSort(int* arr, int size)
{
    // 2) fill this part
    // pre : unordered array arr is delivered, and its length is size
    // post : array arr should have elements in increasing order
    int i;
    int j=0;
    Heap *heap = heapCreate(size);  //create heap
    for (i = 0; i < size; i++){
        heapInsert(heap,arr[i]);
    }                                       //insert array
    while(heap->size != 0) {
        arr[j] = heapDelete(heap);
        j++;
    }//heapDelete is return node, so insert node to arr
}

int main()
{
    int arr[10] = { 1,3,2,5,7,10,8,4,6,9 };
    heapSort(arr, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}