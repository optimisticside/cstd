#include <stdlib.h>
#include "stack.h"

/* creates a new stack */
struct stack *stack_create(size_t capacity) {
    /* allocate stack */
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));

    /* initialize memvers */
    stack->buffer = (void **)calloc(capacity, sizeof(void *));
    stack->capacity = capacity;
    stack->size = 0;

    /* return stack */
    return stack;
}

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