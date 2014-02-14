#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "isMinHeap.h"

static treelink createNode(int item) {
    treelink t = malloc(sizeof (*t));
    t->left = NULL;
    t->right = NULL;
    t->item = item;
    return t;
}

int main(int argc, char **argv) {
    treelink t = NULL;
    printf("Testing on NULL tree.\n");
    assert(isMinHeap(t) == 1);

    printf("Testing on ONE ITEM tree.\n");
    t = createNode(10);
    assert(isMinHeap(t) == 1);

    printf("Testing on TWO ITEM tree.\n");
    t->left = createNode(12);
    assert(isMinHeap(t) == 1);
    free(t->left);
    t->left = NULL;
    t->right = createNode(21);
    assert(isMinHeap(t) == 0);
    

    printf("all tests passed! but will you pass the final tests...\n");
    return EXIT_SUCCESS;
}