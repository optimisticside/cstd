#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

/* queue */
struct queue {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the queue */
    size_t size;        /* size of the queue */
};

void queue_push(struct queue *queue, void *data);
void *queue_pop(struct queue *queue);
void *queue_peek(struct queue *queue);

#endif /* QUEUE_H */