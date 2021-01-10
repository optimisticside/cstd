#ifndef STACK_H
#define STACK_H

#include <stddef.h>

/*
 * stacks are a LIFO data-structure
 * this means that the last thing in is the first thing out
 * it's comparable to a physical stack of books
 * 
 * when you push something to the stack, you're adding it to the top
 * when you pop something from the stack, you're taking it from the top
 * when you peek something from the stack, you're popping it without actually removing it
 */

/* stack */
struct stack {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the stack */
    size_t size;        /* size of the stack */
};

struct stack *stack_create(size_t capacity);
void stack_push(struct stack *stack, void *data);
void *stack_pop(struct stack *stack);
void *stack_peek(struct stack *stack);

#endif /* STACK_H */