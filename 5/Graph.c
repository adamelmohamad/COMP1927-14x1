vlink duplicateList(vlink head) {
    vlink nhead = NULL, ncurr = NULL, curr = head;
    while (curr != NULL) {
        if (nhead == NULL) {
            nhead = duplicateNode(curr);
            ncurr = nhead;
        } else {
            ncurr->next = duplicateNode(curr);
            ncurr = ncurr->next;
        }
        curr = curr->next;
    }
    return nhead;
}

Graph GRAPHcopy(Graph g) {
    // new graph, ng
    Graph ng = malloc(sizeof(*ng));
    ng->V = g->V;
    ng->E = g->E;
    
    // space for array
    ng->array = malloc(sizeof(struct vnode) * ng->V);
    int i;
    for (i = 0; i < ng->V; i++) {
        ng->adj[i] = duplicateList(g->adj[i]);
    }
    
    return ng;
}

void GRAPHdestroy(Graph g) {
    vlink curr;
    int i;
    for (i = 0; i < g->V; i++) {
        curr = NULL;
        while (curr != NULL) {
            vlink temp = curr->next;
            free(curr);
            curr = temp;
        }
    }
    free(g->adj);
    free(g);
}
