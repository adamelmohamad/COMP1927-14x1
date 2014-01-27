//An implementation of a binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"


struct treeNode {
    TreeItem item;
    treelink left;
    treelink right;
};



static treelink createNode(TreeItem item){
     treelink t = (treelink) malloc (sizeof (*t));
     t->item = item;
     t->left = NULL;
     t->right = NULL;
     return t;
}

TreeItem getItem(treelink t){
     assert(t != NULL);
     return t->item;
}

void printTreeNode (treelink t) {
     if(t != NULL);
     printf("%d ",t->item);
}

void preorderTraversal (treelink tree, void (*visit) (treelink)) {
    if (tree == NULL) {
       return;
    }
    (*visit)(tree);
    preorderTraversal (tree->left,visit);
    preorderTraversal (tree->right,visit);
}

treelink insertTreeNode (treelink tree, TreeItem item) {
  if (tree == NULL) {
      tree = createNode(item);
      tree->item = item;
      tree->left = NULL;
      tree->right = NULL;
   
  } else if (tree->item < item) {
      tree->right = insertTreeNode (tree->right, item);
  } else {
      tree->left = insertTreeNode (tree->left, item);
  }
  return tree;
}

int size(treelink t){
    if(t == NULL){
        return 0;
    } else {
        return 1 + size(t->left) + size(t->right);
    }
}

//returns the node of the element with item i
treelink search(treelink t, TreeItem i){
    treelink result = NULL;
    if (t == NULL) {
        result = NULL;
    } else if( i < t->item ){
        result = search(t->left,i); 
    } else if( i > t->item ){
        result = search(t->right,i);   
    } else {
        result = t;
    }    
    return result;
}

treelink searchInsert(treelink t, TreeItem i){
    treelink result = NULL;
    if (t == NULL) {
        result = createTreeNode(i);
    } else if( i < t->item ){
        result = searchInsert(t->left,i); 
    } else if( i > t->item ){
        result = searchInsert(t->right,i);   
    } else { 
        result = t;
    }    
    return result;
}

int countLeaves(treelink t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 1;
    return countLeaves(t->left) + countLeaves(t->right);
}

int countIf (treelink tree, int (*pred)(TreeItem)) {
    if (tree == NULL) return 0;
    return (*pred)(tree->item) + countIf(tree->left) + countIf(tree->right);
}


