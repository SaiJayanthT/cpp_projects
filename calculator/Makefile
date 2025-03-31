CC = g++
CFLAGS = -Wall -I include
SRC = src/main.cpp src/calculator.cpp
OBJ = main.o calculator.o 
TARGET = calculator

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)