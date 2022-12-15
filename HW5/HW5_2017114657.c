#include <stdio.h>
#include "HW5.h"
#include <stdlib.h>
#include <malloc.h>

Heap* heapCreate(int maxSize)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->last = -1;
    heap->size = 0;
    heap->maxSize = maxSize;
    heap->heapArray = (int*)calloc(heap->maxSize, sizeof(int));
    return heap;
}

void heapInsert(Heap* heap, int D1)
{
    if (heap->last != heap->maxSize - 1) {
        heap->last++;
        heap->size++;
        heap->heapArray[heap->last] = D1;
        reheapUp(heap, heap->last);     //plus elements
    }
}

void reheapUp(Heap* heap, int targetIdx)
{
    int parentIdx;
    int* heapArr;
    int hold;

    if(targetIdx)
    {
        heapArr = heap->heapArray;
        parentIdx = (targetIdx - 1) / 2;
        if (heapArr[targetIdx] < heapArr[parentIdx])    //if parent is lager then target, exchange value
        {
            hold = heapArr[parentIdx];
            heapArr[parentIdx] = heapArr[targetIdx];
            heapArr[targetIdx] = hold;
            reheapUp(heap,parentIdx);
        }
    }
}

int heapDelete(Heap* heap)  //delete smallest value and return root
{
    if(heap->size == 0)
        return NULL;
    int root = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[heap->last];
    heap->last--;
    heap->size--;
    reheapDown(heap,0);
    return root;
}


void reheapDown(Heap* heap, int root)
{
    int hold;
    int left;
    int right;
    int smaller;
    int last;

    last = heap->last;
    if ((root * 2 + 1) <= last)
    {
        left = heap->heapArray[root * 2 +1];
        if ((root * 2 + 2) <= last)
            right = heap->heapArray[root * 2 + 2];
        else
            right = NULL;
        if (!right || left<right)   //if right is bigger than left, smaller is root*2+1
            smaller = root * 2 + 1;
        else
            smaller = root * 2 + 2;
        if (heap->heapArray[root] > heap->heapArray[smaller])
        {
            hold = heap->heapArray[root];
            heap->heapArray[root] = heap->heapArray[smaller];
            heap->heapArray[smaller] = hold;
            reheapDown(heap,smaller);
        }
    }
}