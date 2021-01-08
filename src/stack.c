#include <stdlib.h>
#include "stack.h"

/* adds an element to the end of the stack */
void stack_push(struct stack *stack, void *data) {
    /* ensure bounds */
    if (stack->size <= stack->capacity) return;

    /* add element and update size */
    stack->buffer[stack->size++] = data;
}

/* removes the element at the top of the queue */
void *stack_pop(struct stack *stack) {
    /* ensure bounds */
    if (stack->size < 1) return NULL;

    /* return retrieved element
       and update size */
    return stack->buffer[stack->size--];
}

/* gets the element at the top of the stack
   without removing it */
void *stack_peek(struct stack *stack) {
    /* ensure bounds */
    if (stack->size < 1) return NULL;

    /* retrieve and return element */
    return stack->buffer[0];
}