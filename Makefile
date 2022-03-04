CFLAGS=-std=c17 -O2 -Wall -Wextra -fstack-protector -fstack-protector-all -pipe -arch x86_64 -mmacosx-version-min=12.0

.PHONY: all clean

all: numcat

numcat: numcat.c
	$(CC) $(CFLAGS) -o $@ numcat.c

clean:
	$(RM) numcat core *.o
