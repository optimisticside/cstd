#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>

/*
 * dynamic arrays are a very useful data-structure
 * they allow you to store data without having to worry about size
 * whenever you want to add an element and there's not enough space, their data is reallocated
 * 
 * unfortunately, this also means a lot of allocations on the heap
 * they should be avoided where arrays are applicable
 */

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