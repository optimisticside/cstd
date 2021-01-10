#include <stdlib.h>
#include "bitmap.h"

/* gets the index in the bitmap array
   in which a bit would lie */
size_t bitmap_index(size_t entry) {
    return entry / 8;
}

/* gets the bitmask for an entry
   in the bitmap */
size_t bitmap_mask(size_t entry) {
    return 1 << (entry % 8);
}

/* gets a bit from the bitmap */
int bitmap_get(bitmap_t bitmap, size_t entry) {
    return (bitmap[bitmap_index(entry)] & bitmap_mask(entry)) != 0;
}

/* sets a bit in the bitmap */
void bitmap_set(bitmap_t bitmap, size_t entry) {
    bitmap[bitmap_index(entry)] |= bitmap_mask(entry);
}

/* unsets a bit in teh bitmap */
void bitmap_clear(bitmap_t bitmap, size_t entry) {
    bitmap[bitmap_index(entry)] &= ~bitmap_mask(entry);
}