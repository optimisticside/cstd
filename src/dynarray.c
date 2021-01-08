#include "dynarray.h"

void dynarray_resize(struct dynarray *array) {
    /* return if large enough */
    if (array->size + 1 < array->capacity) return;

    /* caluclate size and reallocate buffer */
    size_t new_capacity = array->capacity * array->alpha;
    array->buffer = (void **)realloc(array->buffer, new_capacity * sizeof(void *));

    /* update fields */
    array->capacity = new_capacity;
}

/* adds an element to the end of the array */
void dynarray_add(struct dynarray *array, void *data) {
    /* ensure capacity */
    dynarray_resize(array);

    /* add element */
    array->buffer[array->size++] = data;
}

/* sets an index of the array to a given value */
void dynarray_set(struct dynarray *array, size_t idx, void *data) {
    /* ensure bounds */
    if (idx >= array->size) return;

    /* update element */
    array->buffer[idx] = data;
}

/* removes an index from the array */
void dynarray_remove(struct dynarray *array, size_t idx) {
    /* ensure index exists */
    if (array->size <= idx) return;

    /* update size */
    array->size--;

    /* shift elements after index */
    for (size_t i = idx+1; i < array->size; i++) {
        array->buffer[i-1] = array->buffer[i];
    }
}