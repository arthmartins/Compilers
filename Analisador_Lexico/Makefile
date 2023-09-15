#	Projeto
PROJ = lexic

#	Compilador
CC = gcc

#	.cc
C_SOURCE = lex.yy.cc

#	.h
H_SOURCE = $(wildcard *.h)

#	.l
L_SOURCE = t1.l

#	Flags
CC_FLAGS = -fstack-protector-all	\
		   

#	Compilação e linkagem
$(PROJ): $(C_SOURCE)
	$(CC) $< -o $@ $(CC_FLAGS)

$(C_SOURCE): $(L_SOURCE) $(H_SOURCE)
	flex -o $@ $<