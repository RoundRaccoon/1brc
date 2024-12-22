# ifndef NTHREADS
# NTHREADS=$(shell nproc --all 2>/dev/null || sysctl -n hw.logicalcpu)
# endif

CC=g++

CFLAGS=-std=c++20
# CFLAGS=-std=c17 -O2 -m64 -mcpu=apple-m1 -mtune=native -flto
# CFLAGS+=-Wall -Wextra -Wconversion -Wformat -Wformat=2 -Wimplicit-fallthrough -Wvla
# CFLAGS+=-DNTHREADS=$(NTHREADS)

# ifdef DEBUG
# CFLAGS+=-g -fno-omit-frame-pointer -fsanitize=address,undefined -fstack-protector-strong -fstack-clash-protection
# CFLAGS+=-D_FORTIFY_SOURCE=3
# endif

all: bin/ bin/create-sample

bin/:
	mkdir -p bin/

bin/create-sample: create-sample.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -r bin/