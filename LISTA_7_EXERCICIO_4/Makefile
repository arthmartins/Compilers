#	Projeto
PROJ = cstats

#	Compilador
CC = gcc

#	.cc
C_SOURCE = cstats.yy.cc

#	.h
H_SOURCE = $(wildcard *.h)

#	.l
L_SOURCE = cstats.l

#	Flags
CC_FLAGS = -fstack-protector-all	\
		   

#	Compilação e linkagem
$(PROJ): $(C_SOURCE)
	$(CC) $< -o $@ $(CC_FLAGS)

$(C_SOURCE): $(L_SOURCE) $(H_SOURCE)
	flex -o $@ $<