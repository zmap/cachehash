/*
 * CacheHash Copyright 2014 Regents of the University of Michigan
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 */

#include <string.h>
#include "cachehash.h"
#include <assert.h>
#include <stdio.h>

cachehash *ch = NULL;


void testCreation(void)
{
	ch = cachehash_init(5, NULL);
	assert(ch);
	cachehash_free(ch, NULL);
}

void testPut(void)
{
	ch = cachehash_init(5, NULL);
	char *key = "test-key";
	char *value = "test-value";
	cachehash_put(ch, key, strlen(key), value);
    cachehash_debug_dump(ch);
	key = "test-key-2";
	value = "test-value-2";
	cachehash_put(ch, key, strlen(key), value);
    cachehash_debug_dump(ch);
}

void testPutAndHas(void)
{
	ch = cachehash_init(5, NULL);
	char *key = "test-key";
	char *value = "test-value";
	cachehash_put(ch, key, strlen(key), value);
    cachehash_debug_dump(ch);
    printf("value of has is %s\n", cachehash_has(ch, key, strlen(key)));
	assert(cachehash_has(ch, key, strlen(key)) == value);
	cachehash_free(ch, NULL);
}

void evict_cb(*void)
{

}

void testEvict(void)
{
	ch = cachehash_init(5, NULL);
	char *key = "test-key";
	char *value = "test-value";
	cachehash_put(ch, key, strlen(key), value);
    cachehash_debug_dump(ch);
    printf("value of has is %s\n", cachehash_has(ch, key, strlen(key)));
	assert(cachehash_has(ch, key, strlen(key)) == value);
	cachehash_free(ch, NULL);

}


int main(void)
{
	testCreation();
    printf("--\n");
	testPut();
    printf("--\n");
    testPutAndHas();
}
