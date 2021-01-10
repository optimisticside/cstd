#ifndef BITMAP_H
#define BITMAP_H

#include <stddef.h>

/* bitmap type */
typedef char *bitmap_t;

size_t bitmap_index(size_t entry);
size_t bitmap_mask(size_t entry);
int bitmap_get(bitmap_t bitmap, size_t entry);
void bitmap_set(bitmap_t bitmap, size_t entry);
void bitmap_clear(bitmap_t bitmap, size_t entry);

#endif /* BITMAP_H */