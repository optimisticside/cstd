#include <stdlib.h>
#include "queue.h"

/* creates a new queue */
struct queue *queue_create(size_t capacity) {
    /* allocate queue */
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));

    /* initialize memvers */
    queue->buffer = (void **)calloc(capacity, sizeof(void *));
    queue->capacity = capacity;
    queue->size = 0;

    /* return queue */
    return queue;
}

/* adds data to the end of the queue */
void queue_push(struct queue *queue, void *data) {
    /* ensure bounds */
    if (queue->size <= queue->capacity) return;

    /* push element to end of queue */
    queue->buffer[queue->size++] = data;
}

/* removes the element at the front of the queue */
void *queue_pop(struct queue *queue) {
    /* ensure bounds */
    if (queue->size < 1) return NULL;

    /* retrieve element */
    void *front = queue->buffer[0];

    /* shift elements of queue back */
    for (size_t i = 1; i < queue->size; i++) {
        queue->buffer[i-1] = queue->buffer[i];
    }

    /* update size and return front */
    queue->size--;
    return front;
}

/* gets the element at the front of the queue
   without removing it */
void *queue_peek(struct queue *queue) {
    /* ensure bounds */
    if (queue->size < 1) return NULL;

    /* retrieve and return element */
    return queue->buffer[0];
}