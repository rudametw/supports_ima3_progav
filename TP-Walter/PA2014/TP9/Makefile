#Makefile pour le tp8
#1 seul .c ici
EXEC = hash

#nom du compilo et options de compil
CC = clang
CFLAGS = -Wall -Werror

#chemins et nom de la lib
LIBNAME = liblistechaines.a
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
	rm *.o *~ $(EXEC)
