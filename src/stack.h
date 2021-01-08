#ifndef STACK_H
#define STACK_H

#include <stddef.h>

/* stack */
struct stack {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the stack */
    size_t size;        /* size of the stack */
};

void stack_push(struct stack *stack, void *data);
void *stack_pop(struct stack *stack);
void *stack_peek(struct stack *stack);

#endif /* STACK_H */