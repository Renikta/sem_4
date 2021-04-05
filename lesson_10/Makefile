SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CC = g++

all: normal

normal: sound.o
	$(CC) sound.o -o sfml-app -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.d *.o *.gcda *.gcno *.gcov
