#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "isMinHeapOrdered.h"
//To compile, run and test
//gcc -Wall -Werror -O -o testIsMinHeapOrdered testIsMinHeapOrdered.c isMinHeapOrdered.c

//returns 1 if the tree-based heap is in min-heap order.
//You may assume an empty tree is in min-heap order and so 
//is a single node.
int isMinHeapOrdered(Link n){
    if (n == NULL) {
        return 1;
    }
    if (n->left != NULL && n->left->item < n->item) {
        return 0;
    }
    if (n->right != NULL && n->right->item < n->item) {
        return 0;
    }
    return isMinHeapOrdered(n->left) && isMinHeapOrdered(n->right);
}


