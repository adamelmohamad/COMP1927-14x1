int inDegree(Graph g, Vertex v) {
    int i, count;
    for (i = 0, count = 0; i < g->nV; i++) {
        link curr;
        for (curr = g->adj[i]; curr != NULL; curr++) {
            if (curr->v == v) count++;
        }
    }
    return count;
}