CC = gcc
CFLAGS = -Wall -Wextra -std=c17
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = semitones 

.PHONY: all format clean

all: format $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

format:
	clang-format -i $(SRC)

clean:
	rm -f $(OBJ) $(TARGET)
