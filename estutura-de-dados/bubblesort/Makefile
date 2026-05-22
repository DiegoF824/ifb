TARGET = bubblesort
CC = gcc
CFLAGS = -Wall -Wextra -O2
SRCS = main.c dynamic_array.c bubblesort.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
