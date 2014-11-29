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

    typedef void (*cachehash_evict_cb)(void* key, size_t keylen, void *data) 
    *cachehash cachehash_init(size_t maxitems, cachehash_evict_cb *cb)

Has Item? (returns item without rearranging)::

    void* cachehash_has(cachehash *ch, void *key, size_t key_len)

Get Item! (returns item and moves to be MRU object)::

    void* cachehash_get(cachehash *ch, void *key, size_t key_len)

Put Item! (adds an item to the cachehash)::

    void* cachehash_pet(cachehash *ch, void *key, size_t key_len, void *value)
    
Evict Item! (evicts LRU item if the cachehash is full)::

    void* cachehash_evict_if_full(cachehash *ch)
    
Free Cache Hash (frees all memory used by data structure)::

    void cachehash_free(cachehash *ch, cachehash_process_cb *cb);
    
Iterate (call callback for each item in hash table from MRU -> LRU order)::

    void cachehash_iter(cachehash *ch, cachehash_process_cb *cb);
    
Debug Print (print out entire data structure assuming that keys and values are null-terminated strings)::

    void cachehash_debug_dump(cachehash *ch);

Example
=======

A quick example.


License
=======

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See LICENSE for the specific
language governing permissions and limitations under the License.
