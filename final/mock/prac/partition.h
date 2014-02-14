
typedef struct _list *List;
typedef struct _node *link;
typedef struct _list {
    link first;
    link last;
    int size;
} list;

typedef struct _node {
    int item;
    link next;
} node;


List partition(List original, int data);