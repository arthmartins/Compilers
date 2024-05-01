LEX=flex
YY=bison
CC=g++
BIN = linearscan
L_SOURCE = lexico.l
Y_SOURCE = sintatico.y
CFLAGS = -std=c++23 -g -I. -w

$(BIN): $(L_SOURCE) $(Y_SOURCE)
	$(LEX) $(L_SOURCE)
	$(YY) -d  $(Y_SOURCE)
	$(CC) *.c *cpp $(CFLAGS) -o $(BIN)

run: 
	./$(BIN) 