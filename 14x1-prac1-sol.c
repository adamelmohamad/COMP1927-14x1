#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef struct _node *link;
typedef struct _tnode *treelink;

typedef struct _node {
    int item;
    link next;
} node;

typedef struct _tnode {
    int item;
    treelink left;
    treelink right;
} tnode;

/* --- static functions --- */
static link createNode(int item) {
    link new = malloc(sizeof(struct _node));
    new->item = item;
    new->next = NULL;
    return new;
}

static link append(link head, link append) {
    if (head == NULL) return append; // one line return.

    // append to the end of a linked list
    link curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = append;
    return head;
}

static treelink createTreeNode(int item) {
    treelink new = malloc(sizeof(struct _tnode));
    new->item = item;
    new->left = NULL;
    new->right = NULL;
    return new;
}

/* ----------------- basic list ---------------- */
// countNodes. iterative.
int countNodes(link head) {
    int i = 0;
    link curr = head;
    while (curr != NULL) {
        i++;
        curr = curr->next;
    }
    return i;
}

// count nodes, recursive
int countNodesR(link head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + countNodesR(head->next);
}

link deleteAtPosition(link head, int k) {
    link prev = NULL;
    link curr = head;
    int i = 0;
    while (curr != NULL && i < k) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) { // what are we removing?
        // now remove the required node.
        if (prev != NULL) {
            // if it is not the first one
            prev->next = curr->next; // bridge the gap
        } else {
            head = curr->next; // head is the second one
        }
        free(curr); // free current, no matter what
    }
    return head;
}

link insertAtPosition(link head, int k, link insert) {
    link prev = NULL;
    link curr = head;
    int i = 0;
    while (curr != NULL && i < k) {
        prev = curr;
        curr = curr->next;
    }
    // inserting at beginning
    if (prev == NULL) {
        insert->next = curr; // will adjust null automagically.
        return insert;
    }
    // otherwise, insert at position
    prev->next = insert;
    insert->next = curr; // curr is wherever we're now going
    return head; 
}

link insertInOrder(link head, link insert) {
    link prev = NULL;
    link curr = head;
    while (curr != NULL && insert->item > head->item) { // condition changes: only if current insert node greater than head node
        prev = curr;
        curr = curr->next;
    }

    // this is the same!


    // inserting at beginning
    if (prev == NULL) {
        insert->next = curr; // will adjust null automagically.
        return insert;
    }
    // otherwise, insert at position
    prev->next = insert;
    insert->next = curr; // curr is wherever we're now going
    return head; 
}

link reverse(link head) {
    link curr, prev, temp;
    curr = head;
    prev = NULL;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

link backToFront(link head) {
    // empty and 1 item list are the same
    if (head == NULL || head->next == NULL) {
        return head;
    }

    link curr = head;
    link prev = NULL;
    while (curr->next != NULL) { // find last node
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = head;
    return curr;
}

link frontToBack(link head) {
    // empty and 1 item list are the same
    if (head == NULL || head->next == NULL) {
        return head;
    }
    link second = head->next; // need second one
    link curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }    
    curr->next = head;
    head->next = NULL;
    return second;
}


/* ----------------- basic tree ---------------- */
int countTreeNodes(treelink tree) {
    if (tree == NULL)  {
        return 0;
    }
    return 1 + countTreeNodes(tree->left) + countTreeNodes(tree->right);
}

int countLeaves(treelink tree) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return 1;
    }
    return countLeaves(tree->left) + countLeaves(tree->right);
}

// helper recursive for height
int heightR(treelink tree) {
    if (tree == NULL) {
        return 0;
    }
    // find height of left and right
    int left = heightR(tree->left);
    int right = heightR(tree->right);
    // return the maximum, + 1
    return (left > right ? left : right) + 1;
}

int height(treelink tree) {
    int actualHeight = heightR(tree) - 1;
    // remember, 0 is base height
    return actualHeight >= 0 ? actualHeight : 0;
}

treelink deleteLargest(treelink tree) {
    if (tree != NULL) {

        treelink curr = tree;
        treelink prev = NULL;
        while (curr->right != NULL) {
            prev = curr;
            curr = curr->right;
        }
        if (prev == NULL) {
            tree = curr->left;
        } else {
            prev->right = curr->left;
        }
        free(curr);
    } 
    // return "tree", which is the head
    return tree;
}

int isDegenerate(treelink tree) {
    if (tree == NULL) {
        return 1;
    }
    if (tree->right != NULL && tree->left != NULL) {
        return 0;
    }
    return isDegenerate(tree->left) && isDegenerate(tree->right);
}

void printPrefix(treelink tree) {
    if (tree == NULL) return;
    printf("%d ", tree->item);
    printPrefix(tree->left);
    printPrefix(tree->right);

}


/* ----------------- advanced tree ---------------- */
// recursive helper for isBST
int isBSTR(treelink tree, int min, int max) { 

    if (tree == NULL) {
        return 1;
    }
    if (tree->item < min || tree->item > max) {
        return 0;
    }
    return isBSTR(tree->left, min, tree->item) && isBSTR(tree->right, tree->item, max);
}

int isBST(treelink tree) {
    return isBSTR(tree, INT_MIN, INT_MAX);
}

link listFromTree(treelink tree, link list) {
    if (tree == NULL) {
        return list;
    }
    list = listFromTree(tree->left, list);
    list = append(list, createNode(tree->item));
    list = listFromTree(tree->right, list);
    return list;
}

// copy a tree
treelink copyTree(treelink tree) {
    if (tree == NULL) {
        return NULL;
    }
    tree->left = copyTree(tree->left);
    tree->right = copyTree(tree->right);
    return createTreeNode(tree->item);
}

/* ----------------- main --------------- */
int main(int argc, char *argv[]) {
    treelink tree1 = NULL;
    printf("testing null tree\n");
    assert(isBST(tree1));
    assert(height(tree1) == 0);
    assert(countTreeNodes(tree1) == 0);
    
    printf("testing one node tree \n");
    treelink tree2 = createTreeNode(5);    
    assert(isBST(tree2));
    assert(height(tree2) == 0);
    assert(countTreeNodes(tree2) == 1);
    
    printf("testing bad left subtree\n");
    tree2->left = createTreeNode(6);
    assert(!isBST(tree2)); // not a tree
    
    printf("testing good left subtree\n");    
    tree2->left->item = 3; // note this is already malloc'd.
    assert(isBST(tree2)); // is a tree
    assert(height(tree2) == 1);
    assert(countTreeNodes(tree2) == 2);
    
    printf("testing good left subtree with extra height\n");    
    tree2->left->right = createTreeNode(4);    
    assert(isBST(tree2)); // is a tree    
    assert(height(tree2) == 2);
    assert(countTreeNodes(tree2) == 3);

    printf("test list from tree.\n");
    link list1 = listFromTree(tree2, NULL);
    assert(list1->item == 3);
    assert(list1->next->item == 4);
    assert(list1->next->next->item == 5);
    assert(list1->next->next->next == NULL);

    printf("testing bad left subtree with extra height\n");    
    tree2->left->right->item = 6;
    assert(!isBST(tree2)); // deliberate fail - isBST ignorant way fails this

    return EXIT_SUCCESS;
}