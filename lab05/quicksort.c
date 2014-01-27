#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAIVE_PIVOT 0
#define RANDOM_PIVOT 1
#define MT_PIVOT 2

#define TRUE 1
#define FALSE 0

void quicksort(int a[], int left, int right, int mode);
int partition(int a[], int left, int right, int mode);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Invalid Usage: %s -p(n|r|m) [-q]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int i;
    
    // grab modes 
    int mode;    
    if (strcmp(argv[1], "-pn") == 0) {
        mode = NAIVE_PIVOT;
    } else if (strcmp(argv[1], "-pm") == 0) {
        mode = MT_PIVOT;
    } else if (strcmp(argv[1], "-pr") == 0) {
        mode = RANDOM_PIVOT;
        // seed rand if we are using this
        srand(time(NULL));
    } else {
        printf("Invalid Usage: %s -p(n|r|m) [-q]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // quiet mode
    int quiet = FALSE;
    if (argc == 3 && strcmp(argv[2], "-q") == 0) {
        quiet = TRUE;
    }
    
    // get array size
    int size;
    //if (!quiet) {
        printf("Enter data size: ");
    //}
    scanf("%d", &size);
    
    // get array
    int data[size];
    //if (!quiet) {
        printf("Enter data:\n");
    //}
    for (i = 0; i < size; i++) {
        scanf("%d", &(data[i]));
    }
    
    // quicksort it
    quicksort(data, 0, size-1, mode);
    
    // print it if not quiet
    printf("Sorted with ");
    if (mode == NAIVE_PIVOT) {
        printf("naive");
    } else if (mode == MT_PIVOT) {
        printf("median of three");
    } else if (mode == RANDOM_PIVOT) {
        printf("randomised");
    } else {
        printf("WTF");
    }
    printf(" pivot:\n");
    if (!quiet) {
        // print array
        for (i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }       
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}

void quicksort(int a[], int left, int right, int mode) {
    int i;
    // if left is greater than right, we have sorted.
    if (left >= right) {
        return;
    }
    
    // get the partition; partition appropriately; repeat
    if (mode == MT_PIVOT && (right-left) > 1) {
        // if median of three, and we have three numbers to MT
        // swap the middle element to be at r-1
        int mid = (left+right)/2;
        swap(&(a[right-1]), &(a[mid]));
        
        // bubble sort
        if (a[left] > a[right-1]) {
            swap(&(a[right-1]), &(a[left]));
        }
        
        if (a[right-1] > a[right]) {
            swap(&(a[right-1]), &(a[right]));
        }
        
        if (a[left] > a[right-1]) {
            swap(&(a[right-1]), &(a[left]));
        }
        
        i = partition(a, left+1, right-1, mode);
    } else {
        i = partition(a, left, right, mode);
    }
    // sort the partitions
    // note i is sorted
    quicksort(a, left, i-1, mode);
    quicksort(a, i+1, right, mode);
}

int partition(int a[], int left, int right, int mode) {
    int i, swapIndex = left;
    
    if (mode == RANDOM_PIVOT) {
        // get random element
        int randNum = rand() / (RAND_MAX / (right-left) + 1);
        swap(&(a[left+randNum]), &(a[right]));
    }
    
    // now we have an appropriate pivot in a[r]
    int pivot = a[right];
    
    for (i = left; i < right; i++) {
        if (a[i] <= pivot) {
            swap(&(a[i]), &(a[swapIndex]));
            swapIndex++;
        }
    }
        
    // place the pivot
    swap(&(a[swapIndex]), &(a[right]));
    // return the pivot index
    return swapIndex;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
