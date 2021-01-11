#include <stdlib.h>
#include "map.h"

/* creates a new hashmap */
struct hashmap *map_create(size_t bucket_count, size_t (*hasher)(void *)) {
    /* allocate hashmap */
    struct hashmap *map = (struct hashmap *)malloc(sizeof(struct hashmap));

    /* allocate buckets */
    map->buckets = (struct mapbucket *)calloc(bucket_count, sizeof(struct mapbucket));

    /* initialize bucket lists */
    for (size_t i = 0; i < bucket_count; i++) {
        map->buckets[i].nodes = list_create();
    }

    /* initialize fields */
    map->bucket_count = bucket_count;
    map->hasher = hasher;

    /* return hashmap */
    return map;
}

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
    /* determine the key's bucket */
    size_t hash = map->hasher(key);
    struct mapbucket *bucket = &map->buckets[hash % map->bucket_count];

    /* keep track of location */
    struct listnode *prev = bucket->nodes->head;
    struct listnode *curr = prev;

    /* go through bucket */
    while (curr) {
        /* get current node */
        struct mapnode *node = (struct mapnode *)curr->data;

        /* check location */
        if (node->key == key) {
            /* unlink node */
            prev->next = curr->next;

            /* deallocate bucket and list node */
            free(node);
            free(curr);

            /* return from function */
            return;
        }

        /* update location */
        prev = curr;
        curr = curr->next;
    }
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