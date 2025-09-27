CC = gcc
CFLAGS = -O2 -Wall
TARGET = formatter

all: $(TARGET)

$(TARGET): formatter.c
	$(CC) $(CFLAGS) -o $(TARGET) formatter.c

clean:
	rm -f $(TARGET)
