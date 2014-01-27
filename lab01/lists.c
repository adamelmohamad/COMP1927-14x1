#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "lists.h"

static link createNode(Item data) {
  link newNode = malloc(sizeof(*newNode));
  newNode->data = data;
  newNode->next = next;
}

void printList (link list) {
  link curr = list;
  while (curr != NULL) {
    printf ("[%d]->", curr->item);
    curr = curr->next;
  }
  printf ("[X]\n");
}


int sumListItems (link ls) {
  link curr = ls;
  int count = 0;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  return count;
}

// alternatively,
int sumListItemsR(link ls) {
  if (ls == NULL) return 0;
  return 1 + sumListItemsR(ls->next);
}

void freeList(link list){
   link curr, temp;
   curr = list;
   while (curr != NULL) {
    temp = curr->next;
    free(curr);
    curr = temp;
   }
}

// alternatively
void freeListR(link list) {
  if (list == NULL) return;
  freeListR(list->next);
  free(list);
}

link fromTo (int start, int end) {
  link head = NULL, curr = NULL;
  int i;
  for (i = start; i <= end; i++) {
    if (head == NULL) {
      // opeerate specially
      head = createNode(i);
      curr = head;
    } else {
      curr->next = createNode(i);
      curr = curr->next;
    }
  }
  return head;
}

// recursively...
link fromTo(int start, int end) {
  if (end > start) return NULL;
  link newNode = createNode(start);
  newNode->next = fromTo(start+1, end);
  return newNode;
}

dlink doublify (link list) {
  link curr = list;
  dlink dhead = NULL, dcurr = NULL;
  while (curr != NULL) {
    if (dhead == NULL) {
      dhead = createDNode(curr->data);
      dcurr = dhead;
    } else {
      dcurr->next = createDNode(curr->data);
      dcurr->next->prev = dcurr;
      dcurr = dcurr->next;
    }
    curr = curr->next;
  }
  return dhead;
}

void freeDList(dlink list){
   dlink curr, temp;
   curr = list;
   while (curr != NULL) {
    temp = curr->next;
    free(curr);
    curr = temp;
   }
}