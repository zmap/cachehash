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

Has Item?::

    *void cachehash_has(cachehash *ch, void *key, size_t key_len)

Get Item!::

    *void cachehash_get(cachehash *ch, void *key, size_t key_len)

Put Item!::

    *void cachehash_get(cachehash *ch, void *key, size_t key_len, void *value)

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
