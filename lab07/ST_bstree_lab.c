#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Item.h"
#include "ST.h"

typedef struct STnode* link;
struct STnode { 
  Item item; 
  link left, right; 
  int size;
};

static link rootNodeLink, emptyTree;

link NEW (Item item, link l, link r, int size){ 
  link newLink = malloc (sizeof *newLink); 
  
  newLink->item = item; 
  newLink->left = l; 
  newLink->right = r; 
  newLink->size = size;
  return newLink;
}

void STinit (int n) { 
  rootNodeLink = NEW (NULLitem, NULL, NULL, 0); 
  emptyTree = rootNodeLink;
}

int STcount ()  { 
  return rootNodeLink->size; 
}

Item searchR (link currentLink, Key searchKey) { 
  if (currentLink == emptyTree) {
    return NULLitem;
  }
  Key currentKey = key (currentLink->item);
  if (eq(searchKey, currentKey)) {
    return currentLink->item;
  }
  if (less(searchKey, currentKey)) {
    return searchR (currentLink->left, searchKey);
  } else {
    return searchR (currentLink->right, searchKey);
  }
}

Item STsearch (Key searchKey) { 
  return searchR (rootNodeLink, searchKey); 
} 


link insertR (link currentLink, Item item) { 
  
  if (currentLink == emptyTree) {
    return (NEW (item, emptyTree, emptyTree, 1));
  }
  if (less (key (item), key (currentLink->item))) {
    currentLink->left = insertR (currentLink->left, item);
  } else {
    currentLink->right = insertR (currentLink->right, item);
  } 
  currentLink->size++;
  return (currentLink);
}


void STinsert (Item item) {
  if(STsearch(key(item)) == NULLitem){ 
      rootNodeLink = insertR (rootNodeLink, item);
  }
}



Item selectR (link currentTree, int k) {
  if (currentTree == emptyTree) {
    return NULLitem;
  }
  if (currentTree->left->size == k) {
    return (currentTree->item);
  }
  
  if (currentTree->left->size > k) {
    return (selectR (currentTree->left, k));
  }

  return (selectR (currentTree->right, k - 1 - currentTree->left->size));
}

Item STselect (int k) {
  return (selectR (rootNodeLink, k));
}

link rotLeft (link currentTree) {
  link rotLTree = currentTree->right;
  currentTree->right = rotLTree->left;
  rotLTree->left = currentTree;

  // change the size
  rotLTree->left->size = rotLTree->left->left->size + rotLTree->left->right->size + 1;
  rotLTree->size = rotLTree->left->size + rotLTree->right->size + 1;

  return rotLTree;
}

link rotRight (link currentTree) {
  link rotRTree = currentTree->left;
  currentTree->left = rotRTree->right;
  rotRTree->right = currentTree;
  
  // change the size
  rotRTree->right->size = rotRTree->right->left->size + rotRTree->right->right->size + 1;
  rotRTree->size = rotRTree->right->size + rotRTree->left->size + 1;
  return rotRTree;
}


// partition tree at node with position pos (counting from 0) in the
// sorted sequence of all items, node become new root node.
link partitionR (link currentTree, int pos) {
  int leftSubtreeSize = currentTree->left->size;
  if (leftSubtreeSize > pos) {
    currentTree->left = partitionR (currentTree->left, pos);
    currentTree = rotRight (currentTree) ;
  } else if (leftSubtreeSize < pos) {
    currentTree->right = 
      partitionR (currentTree->right, pos - 1 - leftSubtreeSize);
    currentTree = rotLeft (currentTree) ;    
  }
  return currentTree;
}



void STdelete (Item item) {
  // not implemented yet
}


void sortR (link currentLink, void (*visit)(Item)) { 
  if (currentLink == emptyTree) {
    return;
  }
  sortR (currentLink->left, visit);
  visit (currentLink->item); 
  sortR (currentLink->right, visit);
}

void STsort (void (*visit)(Item)) { 
  sortR (rootNodeLink, visit); 
} 

//prints out the tree in a way that shows the L and R links.
//size of the nodes are in brackets
void dump(link n, int level, int maxLevel){
  if(n == emptyTree){
    printf("X\n");
  } else if (n == NULL){
    //printf("NULL\n");
    } else if (level == maxLevel){
        printf("...\n");
    }else {
        int i;
        printf("%d(%d) ",n->item->keyval,n->size);
       
        printf("\n");
        if (n->left != NULL) {
            for (i = 0; i < level; i++){
                printf("|  ");
            }
            printf("|--L: ");
            dump(n->left, level+1, maxLevel);
        }
        if (n->right != NULL) {
            for (i = 0; i < level; i++){
                printf("|  ");
            }
            printf("|--R: ");
            dump(n->right, level+1, maxLevel);
        }
    }
}
       
void whiteBoxTests(void){
    printf("\nPrinting out the tree\n");
    printf("Sizes of the nodes are in brackets\n");
    dump(rootNodeLink,0,10);
}
