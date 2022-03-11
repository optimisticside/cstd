#include <stdlib.h>
#include "list.h"

/* creates a new list */
struct list *list_create() {
    /* allocate list */
    struct list *list = (struct list *)malloc(sizeof(struct list));

    /* initialize members */
    list->head = NULL;
    list->tail = NULL;

    /* return list */
    return list;
}

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
    /* create and initialize node */
    struct listnode *node = list_create_node(data);
    node->data = data;
    node->next = list->tail;

    /* point tail to node */
    if (list->tail) {
        list->tail->next = node;
    }

    /* update tail of list */
    list->tail = node;

    /* update head of tail if nonexistant */
    if (!list->head) {
        list->head = node;
    }
}

/* gets an element from the list */
void *list_get(struct list *list, size_t idx) {
    /* keep track of location and position */
    struct listnode *curr = list->head;
    size_t pos = 0;

    /* go through the list */
    while (curr) {
        /* check if we're at our destination */
        if (pos == idx) {
            /* return the node's value */
            return curr->data;
        }

        /* update position */
        curr = curr->next;
        pos++;
    }

    /* nothing was found, so return null */
    return NULL;
}

/* deletes an element from the list */
void list_delete(struct list *list, size_t idx) {
    /* keep track of our location and position */
    struct listnode *prev = list->head;
    struct listnode *curr = prev;
    size_t pos = 0;

    /* go through the list */
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

/* reverse the order of the list */
void list_reverse(struct list *list) {
    /* keep track of our location */
    struct listnode *prev = NULL;
    struct listnode *curr = list->head;
    struct listnode *next = NULL;

    /* go through the list */
    while (curr) {
        /* keep track of next node */
        next = curr->next;

        /* reverse pointer of current node */
        curr->next = prev;

        /* check if at end */
        if (!next) {
            /* update head of list */
            list->head = curr;
        }

        /* update position */
        prev = curr;
        curr = next;
    }
}
