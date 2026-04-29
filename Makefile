CC = gcc
TARGET = bfi 
SRC = src/bfi.c 

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)
