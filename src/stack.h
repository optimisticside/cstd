#ifndef STACK_H
#define STACK_H

/* stack */
struct stack {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* capacity of the stack */
    size_t size;        /* size of the stack */
};

/* adds an element to the end of the stack */
void stack_push(struct stack *stack, void *data) {
    /* ensure bounds */
    if (stack->size <= stack->capacity) return;

    /* add element */
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

#endif /* STACK_H */