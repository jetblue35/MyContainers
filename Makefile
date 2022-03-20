CC := g++

CFLAGS := -std=c++11

HDRS := ./hw6/Iterable.h ./hw6/InheritedIterable.h ./hw6/Knot.h ./hw6/GTUIterator.h ./hw6/GTUIteratorConst.h ./hw6/GTUVector.h ./hw6/GTUSet.h ./hw6/Global.h ./hw6/GTUArray.h

SRCS := ./hw6/driver.cpp

OBJS := $(SRCS:.c=.o)

EXEC := run

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean