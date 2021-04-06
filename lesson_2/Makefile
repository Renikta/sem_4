SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
CC = g++

all: normal

normal: sfml.o
	$(CC) sfml.o -o graphics-1 $(SFML_FLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.d *.o *.gcda *.gcno *.gcov
