PROG = calc
CC = gcc
CPPFLAGS = -g -c -Wall
LDFLAGS = 
OBJS = calc.o pushop.o readtkn.o

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS) 

clean:
	rm -f core $(PROG) $(OBJS)