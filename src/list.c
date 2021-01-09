#include <stdlib.h>
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

        /* update position */
        prev = curr;
        curr = next;
    }
}