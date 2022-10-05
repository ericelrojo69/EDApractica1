todo: complejo

complejo.o: complejo.h complejo.cpp
	g++ -c complejo.cpp -Wall -Werror -Wextra

complejo: complejo.o
	g++ complejo.o -o complejo

clean:
	rm complejo.o
	rm complejo
