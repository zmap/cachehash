CC = gcc
CFLAGS = -std=c99 -fpic -Wall -Wextra
LDFLAGS = -ljudy

OBJS = cachehash.o

TARGETS = cachehash.so cachehash.a test_cachehash

all: $(TARGETS)

test_cachehash: test.c $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $< -o $@ $(LDFLAGS)

cachehash.so: $(OBJS)
	$(CC) $(CFLAGS) -shared $(OBJS) -o $@ $(LDFLAGS)

cachehash.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

.PHONY: clean check

clean:
	rm -f $(TARGETS) $(OBJS)

check: test_cachehash
	./test_cachehash
	

