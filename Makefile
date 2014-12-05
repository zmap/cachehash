CC = gcc
CFLAGS = -std=c99 -fpic -Wall -Wextra
LDFLAGS = -ljudy

OBJS = cachehash.o

TARGETS = libcachehash.so libcachehash.a test_cachehash

all: $(TARGETS)

test_cachehash: test.c $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $< -o $@ $(LDFLAGS)

libcachehash.so: $(OBJS)
	$(CC) $(CFLAGS) -shared $(OBJS) -o $@ $(LDFLAGS)

libcachehash.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

.PHONY: clean check

clean:
	rm -f $(TARGETS) $(OBJS)

check: test_cachehash
	./test_cachehash
	

