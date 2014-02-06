List merge(List list1, List list2) {
    List newList = newList();
    newList->first = mergeLinks(list1->first, list2->first);
    newList->size = list1->size + list2->size;
    // free the lists?
    free(list1);
    free(list2);
    return newList;
}

link mergeLinks(link l1, link l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1 > l2) {
        l2->next = mergeLinks(l1, l2->next);
        return l2;
    } else {
        l1->next = mergeLinks(l1->next, l2);
        return l1;
    }
}