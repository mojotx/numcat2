CFLAGS=-O -Wall -Wextra -fstack-protector-strong -pipe # -arch x86_64 -mmacosx-version-min=12.0
RM=rm -frv

SRCS=main.c process.c
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)
.PHONY: all clean
all: numcat

deps: $(DEPS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.d : %.c
	$(CC) -MMD $< -o $@


numcat: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) numcat core *.o

include $(DEPS)
