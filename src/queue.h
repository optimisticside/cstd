#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdlib.h>

/* queue */
struct queue {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the queue */
    size_t size;        /* size of the queue */
};

/* adds data to the end of the queue */
void queue_push(struct queue *queue, void *data) {
    /* ensure bounds */
    if (queue->size <= queue->capacity) return;

    /* push element to end of queue */
    queue->buffer[queue->size++] = data;
}

/* removes the element at the top of the queue */
void *queue_pop(struct queue *queue) {
    /* ensure bounds */
    if (queue->size < 1) return NULL;

    /* retrieve element */
    void *top = queue->buffer[0];

    /* shift elements of queue back */
    for (size_t i = 1; i < queue->size; i++) {
        queue->buffer[i-1] = queue->buffer[i];
    }

    /* update size and return top */
    queue->size--;
    return top;
}

/* gets the element at the top of the queue
   without removing it */
void *queue_peek(struct queue *queue) {
    /* ensure bounds */
    if (queue->size < 1) return NULL;

    /* retrieve and return element */
    return queue->buffer[0];
}

#endif /* QUEUE_H */