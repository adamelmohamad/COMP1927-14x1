// isSorted
int isSorted(link list) {
    link curr = list;
    link prev != NULL;
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
        link curr = l2->first;
        
        while (curr->next != NULL) {
            curr = curr->next;
        }
        
        l1->last = curr; // in which case, it equals to the last of the other one
        curr->next = l1->first; // bridge the gap
        l1->first = l2->first; // first changes    
        l1->size = l1->size + l2->size;
    }
    // l2 changes
    l2->first = NULL;
    l2->last = NULL;
    l2->size = 0;
}

// isDegenerate was in the questions I gave!

// prune tree
// we need to store our current level! store in curr
treelink pruneTreeR(tree root, int level, int curr) {
    if (curr >= level) { // level too big!
        return NULL;
    }
    root->left = pruneTreeR(root->left, level, curr + 1);
    root->right = pruneTreeR(root->right, level, curr + 1);
    return root;
}

treelink pruneTree(tree root, int level) {
    return pruneTreeR(root, level, 0);
}