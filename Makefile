AR=ar
FLAGS= -Wall -g

all: libmysort.a  libmytxt.a isort txtfind
isort: isort.o libmysort.a
	gcc $(FLAGS) -o isort isort.o libmysort.a
txtfind: txt.o libmytxt.a
	gcc $(FLAGS) -o txtfind txt.o libmytxt.a
libmysort.a: funcSort.o
	ar -rcs libmysort.a funcSort.o
libmytxt.a: funcTxt.o
	ar -rcs libmytxt.a funcTxt.o
isort.o: isort.c funcSort.h
	gcc $(FLAGS) -c isort.c
funcSort.o: funcSort.c funcSort.h
	gcc $(FLAGS) -c funcSort.c
txt.o: txt.c funcTxt.h
	gcc $(FLAGS) -c txt.c
funcTxt.o: funcTxt.c funcTxt.h
	gcc $(FLAGS) -c funcTxt.c




.PHONY: clean all

clean:
	rm -f *.o *.a isort txtfind