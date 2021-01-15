CFLAGS = -o 
CPPFLAGS = -std=c++11
CC = g++
SRC = main.cpp SpellCheck.cpp
OBJ = $(SRC:.cpp = .o)

run: $(OBJ)
	$(CC) $(CFLAGS) run $(OBJ) $(CPPFLAGS)

clean:
	rm -f core *.o
