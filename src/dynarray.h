#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>

/* dynamic array */
struct dynarray {
    void **buffer;      /* pointer to the data */
    size_t capacity;    /* amount of elements the array can fit */
    size_t size;        /* current size of array */
    size_t alpha;       /* how to calculate new size (new_size = old_size * alpha) */
};

void dynarray_resize(struct dynarray *array);
void dynarray_add(struct dynarray *array, void *data);
void dynarray_set(struct dynarray *array, size_t idx, void *data);
void dynarray_remove(struct dynarray *array, size_t idx);

#endif /* DYNARRAY */