#Makefile pour le controle TP
#nom de l'executable
EXEC = tpnote

#nom du compilo et options de compil
CC = gcc
CFLAGS = -Wall -g

CFILES = listedates.c main.c 
OBJS  = $(patsubst %.c,%.o,$(CFILES)) 

all : $(EXEC)

$(EXEC) : $(OBJS) 
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c listedates.h
	$(CC) $(CFLAGS) $(INCLUDES) -c  $<

clean:
	rm *.o *~ $(EXEC)
