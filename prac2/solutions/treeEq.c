int treeEq(treelink tree1, treelink tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 == NULL && tree2 != NULL) {
        return 0;
    } 
    if (tree2 == NULL && tree1 != NULL) {
        return 0;
    }
    if (tree1->item != tree2->item) {
        return 0;
    }
    return treeEq(tree->left, tree2->left) && treeEq(tree->right, tree2->right);
}