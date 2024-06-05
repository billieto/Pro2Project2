CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -c
PROGRAM = main
OBJECTS = main.o lists.o inputnfiles.o
HEADERS = main.h lists.h inputnfiles.h
TARGET = main

all: $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(TARGET) $(OBJECTS)

main.o: main.c $(HEADERS)
	$(CC) $(OBJFLAGS) main.c

lists.o: lists.c $(HEADERS)
	$(CC) $(OBJFLAGS) lists.c

inputnfiles.o: inputnfiles.c $(HEADERS)
	$(CC) $(OBJFLAGS) inputnfiles.c

$(TARGET): $(OBJECTS) $(HEADERS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGET)

clean:
	rm -f *.txt *.o

run:
	./$(TARGET)
