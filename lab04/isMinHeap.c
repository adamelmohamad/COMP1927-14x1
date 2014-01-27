#include "isMinHeap.h"
//To compile, run and test
//gcc -Wall -Werror -O -o testIsMinHeap testIsMinHeap.c isMinHeap.c

// heaper function
int isMinHeapH(int heap[], int heapSize, int i) {
    if (i > heapSize) {
        return 1;
    }
    // check left
    if (2*i <= heapSize && heap[2*i] < heap[i]) {
        return 0;
    }
    // check right
    if (2*i+1 <= heapSize && heap[2*i+1] < heap[i]) {
        return 0;
    }
    return isMinHeapH(heap, heapSize, 2*i) && isMinHeapH(heap, heapSize, 2*i+1);
}

//return 1 if the array heap with a sepcified number of items is in heap order 
//You must assume that the heap items are in indexes 1..heapSize and that index 0 
//is empty and not used to store items.
int isMinHeap(int heap[], int heapSize){
    return isMinHeapH(heap, heapSize, 1);
}