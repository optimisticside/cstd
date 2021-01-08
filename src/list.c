#include "list.h"

/* creates a node */
struct listnode *list_create_node(void *data) {
    /* allocate node */
    struct listnode *node = (struct listnode *)malloc(sizeof(struct listnode));

    /* update fields */
    node->next = NULL;
    node->data = data;

    /* return node */
    return node;
}

/* adds an element to the end of the list */
void list_add(struct list *list, void *data) {
    /* keep track of current node */
    struct listnode *curr;

    /* create head if it doesn't exist */
    if (!list->head) {
        list->head = list_create_node(data);
        return;
    }

    /* go through list and get tail */
    curr = list->head;
    while (curr->next) {
        curr = curr->next;
    }

    /* update tail of list to point to new node */
    curr->next = list_create_node(data);
}

/* deletes an element from the list */
void list_delete(struct list *list, size_t idx) {
    /* keep track of our location and position */
    struct listnode *prev = list->head;
    struct listnode *curr = prev;
    size_t pos = 0;

    while (curr) {
        /* check if we're at the right position */
        if (pos == idx) {
            /* remove node from list */
            prev->next = curr->next;

            /* deallocate node */
            free(curr);
        }

        /* update position */
        prev = curr;
        curr = curr->next;
        pos++;
    }
}