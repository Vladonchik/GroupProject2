
CFLAGS =-framework SDL2  -O4 -Wall -pedantic -std=c99 -lm
INCS = parser.h 
TARGET = main
SOURCES =  parser.c $(TARGET).c
LIBS = 
CC = gcc


all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) $(INCS) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

run: all
	$(TARGET) 
