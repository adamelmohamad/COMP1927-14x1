int treeEqR(treelink tree1, treelink tree2) {
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
    return treeEqRtree->left, tree2->left) && treeEqR(tree->right, tree2->right);
}

// if it had an ADT...
int treeEq(Tree tree1, Tree tree2) {
    return treeEqR(tree1->root, tree2->root);
}