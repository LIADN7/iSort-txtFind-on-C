AR=ar
FLAGS= -Wall -g

all: libmysort.a  libmytxt.a isort txtfind
isort: libmysort.a
	gcc $(FLAGS) -o isort libmysort.a
txtfind: libmytxt.a
	gcc $(FLAGS) -o txtfind libmytxt.a
libmysort.a: isort.o
	ar -rcs libmysort.a isort.o
libmytxt.a: main.o
	ar -rcs libmytxt.a main.o
isort.o: isort.c func.c
	gcc $(FLAGS) -c isort.c
main.o: main.c funcTxt.c
	gcc $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a isort txtfind