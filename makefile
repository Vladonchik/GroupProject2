
CFLAGS =-framework SDL2  -O4 -Wall -pedantic -std=c99 -lm
INCS = 
TARGET = main
SRCDIR = ./sources/
SOURCES = $(SRCDIR)actionQueueDataStructure.c $(SRCDIR)parser.c $(SRCDIR)$(TARGET).c 
LIBS = 
CC = gcc


all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) $(INCS) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

run: all
	$(TARGET) 
