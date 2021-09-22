CC=gcc
CCFLAGS=-Wall -Werror -Wextra -pedantic
DEBUG_CCFLAGS=-ggdb
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=monty

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CCFLAGS)

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

debug: $(OBJECTS)
	$(CC) -o $(TARGET) $^ $(DEBUG_CCFLAGS) $(CCFLAGS)

clean:
	rm -f *.o $(TARGET)