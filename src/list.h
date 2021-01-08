#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/*
 * linked lists are a powerful data-structure
 * they consist of units called nodes
 * each node has a value, and the location of the next node
 * 
 * they are very fast removing and adding nodes
 * unfortunately, this also means that they are slow for getting nodes
 */

/* linked list node */
struct listnode {
    void *data;             /* the data the node holds */
    struct listnode *next;  /* the next node in the list */
};

/* linked list */
struct list {
    struct listnode *head;  /* first node in list */
};

struct listnode *list_create_node(void *data);
void list_add(struct list *list, void *data);
void *list_get(struct list *list, size_t idx);
void list_delete(struct list *list, size_t idx);
void list_reverse(struct list *list);

#endif /* LIST_H */