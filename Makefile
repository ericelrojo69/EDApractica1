main: ./src/complejo.h ./src/complejo.cpp ./src/main.cpp
	clang++ ./src/main.cpp -Wall -Werror -Wextra -o main.out

clean:
	rm complejo
