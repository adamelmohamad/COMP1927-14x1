int inDegree(Graph g, Vertex v) {
    if (v < 0 || v >= g->nV) {
        return -1;
    }
    int i, count;
    for (i = 0, count = 0; i < g->nV; i++) {
        link curr;
        for (curr = g->adj[i]; curr != NULL; curr = curr->next) {
            if (curr->v == v) count++;
        }
    }
    return count;
}
