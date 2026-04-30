CC = gcc
TARGET = bfi 
SRC = src/bfi.c 

all:
	$(CC) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)
