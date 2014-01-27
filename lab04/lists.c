link insertInOrder(link head, link insert) {
    link prev = NULL;
    link curr = head;
    while (curr != NULL && insert->item > head->item) { // condition changes: only if current insert node greater than head node
        prev = curr;
        curr = curr->next;
    }

    // inserting at beginning
    if (prev == NULL) {
        insert->next = curr; // will adjust null automagically.
        return insert;
    }
    prev->next = insert;
    insert->next = curr; // curr is wherever we're now going
    return head;
}



link insertionSort(link list) {
    link curr = list;
    link newHead = NULL;
    while (curr != NULL) {
        link temp = curr->next;
        newHead = insertInOrder(newHead, curr);
        curr = temp; // move along
    }
    return newHead;
}