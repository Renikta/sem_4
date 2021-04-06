SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
CC = g++

all: normal

normal: polygon.o
	$(CC) polygon.o -o graphics-1 $(SFML_FLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.d *.o *.gcda *.gcno *.gcov
