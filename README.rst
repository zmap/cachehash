CacheHash
=========

An efficient C hash table data structure that supports a limited number of
hash table items and evicts the least recently used object (with a callback)
on insertion. This is accomplished with a Judy Array where hash table items
point to an statically allocated doubly-linked-list where head is MRU object
and tail is LRU. On object access, object is moved to the head of the list.

This is primarily intended for caches. 

API
===

Initialization::

    *cachehash cachehash_init(size_t maxitems, evict_cb *cb)

Has Item?::
    *void cachehash_has(void *key, size_t **key_len)

Get Item!::

    *void cachehash_get(void *key, size_t **key_len)

Put Item!::

    *void cachehash_get(void *key, size_t **key_len, void *value)
