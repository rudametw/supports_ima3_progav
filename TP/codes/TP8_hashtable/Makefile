#Makefile pour le TP Hash Table

#Nom de l'éxécutable à créer
EXEC = hash

#nom du compilo
CC = gcc

#options de compil, pret pour utiliser valgrind
CFLAGS = -Wall -Wextra -g -O0

#chemins et nom de la lib
#LIBNAME = liblistechaines.a
PATHLIBA = .
PATHLIBH = .

#flags de compil : le .h à la compil, la lib à l'édition de lien
LDFLAGS = -L$(PATHLIBA) -llistechaines
INCLUDES= -I$(PATHLIBH)

CFILES = $(EXEC).c
OBJS  = $(patsubst %.c,%.o,$(CFILES))

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c  $<

clean:
	rm -f ${OBJS} $(EXEC)

.PHONY : clean
