#include <stdint.h>
#include <stddef.h>

typedef struct cachehash_s cachehash;
typedef void (cachehash_process_cb)(void *data);
cachehash* cachehash_init(size_t maxitems, cachehash_process_cb *cb);
void* cachehash_has(cachehash *ch, void *key, size_t keylen);
void* cachehash_get(cachehash *ch, void *key, size_t keylen);
void cachehash_put(cachehash *ch, void *key, size_t keylen, void *value);
void cachehash_free(cachehash *ch, cachehash_process_cb *cb);
void* cachehash_evict_if_full(cachehash *ch);
void cachehash_iter(cachehash *ch, cachehash_process_cb *cb);
void cachehash_debug_dump(cachehash *ch);
