CC = g++
CFLAGS = -Wall -I include
SRC = src/main.cpp src/shell.cpp
OBJ = main.o shell.o 
TARGET = shell

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)