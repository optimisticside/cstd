#ifndef MAP_H
#define MAP_H

#include "list.h"

/*
 * a hash map is a very powerful data-structure
 * it's also known as an associative array
 * 
 * hashmaps are split into buckets
 * each bucket consists of a linked list of elements
 * each element has a key, value, and unique hash
 * the hash is used to determine the node's bucket
 */

/* hash map node */
struct mapnode {
    void *data;     /* the node's data */
    void *key;      /* key of node */
    size_t hash;    /* hash of node */
};

/* hash map node */
struct mapbucket {
    struct list *nodes;   /* nodes in bucket */
};

/* hash map */
struct hashmap {
    struct mapbucket *buckets;  /* buckets in hashmap */
    size_t bucket_count;        /* amount of buckets */
    size_t (*hasher)(void *);   /* hasher function */
};

struct mapnode *map_add(struct hashmap *map, void *key, void *data);
struct mapnode *map_find(struct hashmap *map, void *key);
void map_set(struct hashmap *map, void *key, void *data);
void map_remove(struct hashmap *map, void *key);
void *map_get(struct hashmap *map, void *key);

#endif /* MAP_H */