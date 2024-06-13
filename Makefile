CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -c
PROGRAM = main
OBJECTS = main.o lists.o inputnfiles.o bonus.o
HEADERS = main.h lists.h inputnfiles.h bonus.h
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) $(OBJFLAGS) main.c

lists.o: lists.c $(HEADERS)
	$(CC) $(CFLAGS) $(OBJFLAGS) lists.c

inputnfiles.o: inputnfiles.c $(HEADERS)
	$(CC) $(CFLAGS) $(OBJFLAGS) inputnfiles.c

bonus.o: bonus.c $(HEADERS)
	$(CC) $(CFLAGS) $(OBJFLAGS) bonus.c

clean:
	rm -f *.txt *.o $(TARGET)

leak:
	valgrind --leak-check=full ./$(TARGET)

run:
	./$(TARGET)
