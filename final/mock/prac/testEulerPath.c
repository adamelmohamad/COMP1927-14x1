#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "eulerPath.h"
#define MAXV 5
#define MAXE 10

Graph graphScan(char *file){
    int v,w;
    int V;
    FILE *in = fopen(file, "r");
    fscanf(in, "%d",&V);
    Graph g = GRAPHinit(V);
    while(fscanf(in,"%d %d",&v,&w) == 2){
        GRAPHinsertE(g,EDGE(v,w));
    }
    fclose(in);
    return g;
}

int main(int argc, char * argv[]){
    Graph g1 = graphScan("test1.txt");
    printf("test1.txt\n");
    GRAPHshow(g1);
    assert(eulerPath(g1) == 1);
    GRAPHdestroy(g1);

    Graph g2 = graphScan("test2.txt");
    printf("test2.txt\n");
    GRAPHshow(g2);
    assert(eulerPath(g2) == 2);
    GRAPHdestroy(g2);


    Graph g3 = graphScan("test3.txt");
    printf("test3.txt\n");
    GRAPHshow(g3);
    assert(eulerPath(g3) == 0);
    GRAPHdestroy(g3);

    return 0;
}
