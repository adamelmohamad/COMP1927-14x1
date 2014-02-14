typedef struct _tree *treelink;
typedef struct _tree {
    int item;
    treelink left;
    treelink right;
} tree;

int isMinHeap(treelink t);