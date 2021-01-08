#ifndef DEQUE_H
#define DEQUE_H

#include <stddef.h>

/* deque */
struct deque {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the deque */
    size_t size;        /* size of the deque */
};

void deque_push_front(struct deque *deque, void *data);
void *deque_pop_front(struct deque *deque);
void *deque_peek_front(struct deque *deque);

void deque_push_back(struct deque *deque, void *data);
void *deque_pop_back(struct deque *deque);
void *deque_peek_back(struct deque *deque);

#endif /* DEQUE_H */