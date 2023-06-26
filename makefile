CC       = g++
CCFLAGS  = -std=c++2a -g -Wall -Ofast

lib: Raylib.h Raylib.cpp
	$(CC) $(CCFLAGS) -c Raylib.cpp -o Raylib.o
	ar -rcs libRaylib.a  Raylib.o

.PHONY: clean tidy
clean:
	rm -f Raylib.o libRaylib.a 

tidy:
	rm -f Raylib.o 

