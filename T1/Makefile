#	Projeto
PROJ = portugol

#	.c
C_SOURCE = $(wildcard *.cpp)

#	.h
H_SOURCE = $(wildcard *.hpp)

#	.o
OBJ = $(C_SOURCE:.cpp = .o)

#	Compilador
CC = g++

#	Flags
CC_FLAGS = -fstack-protector-all	\
		   -g						\
		   -fstack-check

#	Compilação e linkagem
$(PROJ): $(OBJ)
	$(CC) -o $@ $^
	
%.o: %.cpp %.hpp
	$(CC) -o $@ $< $(CC_FLAGS)
	
main.o: main.cpp $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)