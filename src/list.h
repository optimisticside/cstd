#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>

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
void list_delete(struct list *list, size_t idx);

#endif /* LIST_H */