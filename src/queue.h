#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

/*
 * queues are a FIFO data-structure
 * this means that the first thing in is the first thing out
 * it's comparable to a physical line of people waiting
 * 
 * when you push something to the stack, you're adding it to the to the back
 * when you pop something from the stack, you're taking it from the front
 * when you peek something from the queue, you're popping it without actually removing it
 */

/* queue */
struct queue {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the queue */
    size_t size;        /* size of the queue */
};

struct queue *queue_create(size_t capacity);
void queue_push(struct queue *queue, void *data);
void *queue_pop(struct queue *queue);
void *queue_peek(struct queue *queue);

#endif /* QUEUE_H */