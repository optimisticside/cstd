#include <stdlib.h>
#include "deque.h"

/* creates a new deque */
struct deque *deque_create(size_t capacity) {
    /* allocate deque */
    struct deque *deque = (struct deque *)malloc(sizeof(struct deque));

    /* initialize memvers */
    deque->buffer = (void **)calloc(capacity, sizeof(void *));
    deque->capacity = capacity;
    deque->size = 0;

    /* return deque */
    return deque;
}

/* adds an element to the front of the deque */
void deque_push_front(struct deque *deque, void *data) {
    /* ensure bounds */
    if (deque->size >= deque->capacity) return;

    /* update size and shift elements right */
    deque->size++;
    for (size_t i = 1; i < deque->size; i++) {
        deque->buffer[i-1] = deque->buffer[i];
    }

    /* add element  */
    deque->buffer[0] = data;
}

/* removes the element at the front of the deque */
void *deque_pop_front(struct deque *deque) {
    /* ensure bounds */
    if (deque->size < 1) return NULL;

    /* retrieve element */
    void *front = deque->buffer[0];

    /* shift elements of deque back */
    for (size_t i = 1; i < deque->size; i++) {
        deque->buffer[i-1] = deque->buffer[i];
    }

    /* update size and return front */
    deque->size--;
    return front;
}

/* gets the element at the top of the deque
   without removing it */
void *deque_peek_front(struct deque *deque) {
    /* ensure bounds */
    if (deque->size < 1) return NULL;

    /* retrieve and return element */
    return deque->buffer[0];
}

/* adds an element to the end of the deque */
void deque_push_back(struct deque *deque, void *data) {
    /* ensure bounds */
    if (deque->size <= deque->capacity) return;

    /* add element and update size */
    deque->buffer[deque->size++] = data;
}

/* removes the element at the top of the queue */
void *deque_pop_back(struct deque *deque) {
    /* ensure bounds */
    if (deque->size < 1) return NULL;

    /* return retrieved element
       and update size */
    return deque->buffer[deque->size--];
}

/* gets the element at the top of the deque
   without removing it */
void *deque_peek_back(struct deque *deque) {
    /* ensure bounds */
    if (deque->size < 1) return NULL;

    /* retrieve and return element */
    return deque->buffer[0];
}