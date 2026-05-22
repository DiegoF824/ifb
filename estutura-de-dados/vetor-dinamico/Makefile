TARGET = vetor-dinamico
CC = gcc
CFLAGS = -Wall -Wextra -O2
SRCS = vetor-dinamico.c dynamic_array.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
