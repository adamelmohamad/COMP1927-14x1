// isSorted
int isSorted(link list) {
    link curr = list;
    link prev = NULL;
    while (curr != NULL) {
        if (prev != NULL) { // only check if we have prev
            if (curr->item < prev->item) {
                return 0;
            }
        }
    }
    return 1;
}

// SUMS WAS IN THE QUESTIONS I GAVE
// NO LOOPS O(1)!!!

// append
void append(list l1, list l2) { // note this is a STRUCT with a pointer to first!
    // sad cases
    if (l2 == NULL) {
        return; // already done!
    }
    if (l1 == NULL) {
        l1->first = l2->first;
        l1->last = l2->last;
        l1->size = l2->size;
    } else {
        l1->last = l2->last; // in which case, it equals to the last of the other one
        l2->last->next = l1->first; // bridge the gap
        l1->first = l2->first; // first changes    
        l1->size = l1->size + l2->size;
    }
    // l2 changes
    l2->first = NULL;
    l2->last = NULL;
    l2->size = 0;
}

// isDegenerate was in the questions I gave!
/* WAY #1 */
void freeTree(tree root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

treelink pruneTree(tree root, int depth) {
    if (root == NULL) {
        return NULL;
    }
    if (curr <= 0) { // level too big!
        freeTree(root); // free the rest
        return NULL;
    }
    root->left = pruneTree(root->left, level - 1);
    root->right = pruneTree(root->right, level - 1);
    return root;
}