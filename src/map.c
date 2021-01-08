#include <stdlib.h>
#include "map.h"

/* adds a node to a hashmap */
struct mapnode *map_add(struct hashmap *map, void *key, void *data) {
    /* allocate node */
    struct mapnode *node = (struct mapnode *)malloc(sizeof(struct mapnode));

    /* update fields */
    node->key = key;
    node->data = data;
    node->hash = map->hasher(key);

    /* insert into node */
    struct mapbucket *bucket = node->hash % map->bucket_count;
    list_add(bucket->nodes, node);

    /* return node */
    return node;
}

/* finds a node by its key */
struct mapnode *map_find(struct hashmap *map, void *key) {
    /* determine the key's bucket */
    size_t hash = map->hasher(key);
    struct mapbucket *bucket = &map->buckets[hash % map->bucket_count];

    /* search for node in bucket */
    struct listnode *curr = bucket->nodes->head;
    while (curr) {
        /* check the key */
        struct mapnode *node = (struct mapnode *)curr->data;
        if (node->key == key) {
            /* return the node's value */
            return curr->data;
        }

        /* go to next node */
        curr = curr->next;
    }

    /* return null */
    return NULL;
}

/* updates an index of the node */
void map_set(struct hashmap *map, void *key, void *data) {
    /* try finding the node */
    struct mapnode *node = map_find(map, key);

    /* update existing node if it exists */
    if (node) {
        node->data = data;
        return;
    }

    /* add node */
    map_add(map, key, data);
}

/* removes a node from a map by it's index */
void map_remove(struct hashmap *map, void *key) {
    
}

/* gets a node's value from it's index */
void *map_get(struct hashmap *map, void *key) {
    /* find node */
    struct mapnode *node = map_find(map, key);

    /* return node if it exists */
    if (node) {
        return node->data;
    }

    /* return null */
    return NULL;
}