#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "partition.h"



static link createNode(int item) {
    link t = malloc(sizeof (*t));
    t->next = NULL;
    t->item = item;
    return t;
}

int main(int argc, char **argv) {
    printf("testing (1,3) partitioning at 2\n");
    List l = malloc(sizeof(*l));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;

    l->first = createNode(1);
    l->first->next = createNode(3);
    l->last = l->first->next;
    l->size = 2;

    List l1 = l;
    List l2 = partition(l1, 2);
    assert(l1->size == 1);
    assert(l2->size == 1);
    assert(l1->last == l1->first);
    assert(l2->last == l2->first);
    assert(l1->first->item == 1);
    assert(l2->first->item == 3);

    printf("all tests passed! but will you pass the final tests...\n");
    return EXIT_SUCCESS;
}