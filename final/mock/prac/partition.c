#include <stdlib.h>
#include <stdio.h>
#include "partition.h"

/*
    I actually ran out of linked list questions so...

    Given an original list, and returns a list of all items bigger than 
    the original list whilst keeping any items less than the original list 
    in the original list. 

    e.g. on [1]->[2]->[8]->[4], partition(original, 4) will give us 
    > [1]->[2] as the original list 
    > and returns a new list [8]->[4]

    Compile with:
    gcc -Wall -Werror -O -o partitionTest partition.c testPartition.c
*/

List partition(List original, int data) {
    return NULL;
}