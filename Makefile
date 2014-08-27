CC = gcc
CFLAGS=-Wall -g

PROG=	ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17
BIN=./bin/
LIST=$(addprefix $(BIN), $(PROG))
COMP=$(addsuffix $(PROG), .c)

all: $(LIST)

$(BIN)%: ./%.c 
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -f ex[0-9]
	rm -f ex1[0-9]
