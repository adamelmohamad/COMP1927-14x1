#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#include <assert.h>

#define DEFAULT_SIZE 100
#define UNDEFINED -1

struct queueImp{
    Item *items;
    int offset;
    int size;
    int maxSize;
};

//O(1)
Queue createQueue() {
    Queue q = malloc(sizeof(struct queueImp));
    q->items = malloc(DEFAULT_SIZE * sizeof(Item));
    q->size = 0;
    q->offset = 0;
    q->maxSize = DEFAULT_SIZE;
    return q;
}

void destroyQueue(Queue q) {
    assert(q != NULL);
    free(q->items);
    free(q);
}

//O(1)
int queueSize(Queue q){
    assert(q != NULL);
    return (q->size);
}

//O(1) average case...
// "overflow proof"
void putQueue(Queue q, Item i){
    assert(q != NULL);
    if (q->offset + q->size >= q->maxSize) {
        if (q->size >= q->maxSize) {
            fprintf(stderr, "queue overflow\n");
            abort();
        } else {
            // move items back if we can
            int i;
            for (i = 0; i < q->size; i++) {
                q->items[i] = q->items[q->offset + i];
            }
            q->offset = 0;
        }
    }
    q->items[q->offset + q->size++]  = i;
}

//O(1) 
Item getQueue(Queue q) {
    assert(q != NULL);
    int item = UNDEFINED;
    
    if (q->size > 0) {
        item = q->items[q->offset++];
        q->size--;
    } else {
        fprintf(stderr, "queue underflow\n");
        abort();
    }
    return item;     
}
