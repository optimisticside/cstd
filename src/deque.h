#ifndef DEQUE_H
#define DEQUE_H

#include <stddef.h>

/*
 * a deque is also knwon as a double-ended queue
 * dequeues allow operations on both the front and the back it
 * this means that they can be used as a queue or a stack
 */

/* deque */
struct deque {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the deque */
    size_t size;        /* size of the deque */
};

struct deque *deque_create(size_t capacity);

void deque_push_front(struct deque *deque, void *data);
void *deque_pop_front(struct deque *deque);
void *deque_peek_front(struct deque *deque);

void deque_push_back(struct deque *deque, void *data);
void *deque_pop_back(struct deque *deque);
void *deque_peek_back(struct deque *deque);

#endif /* DEQUE_H */