CC=gcc
CFLAGS=-Wall -g
OBJ=terminal.o terminalExample.o
EXEC=terminalExample


$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

terminalExample.o: terminalExample.c terminal.h
	$(CC) $(CFLAGS) -c terminalExample.c

clean:
	rm -f $(EXEC) $(OBJ)