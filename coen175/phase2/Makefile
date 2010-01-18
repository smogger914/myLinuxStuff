CC	= gcc
CFLAGS	= -g -Wall -Wmissing-prototypes
LIBS	=
OBJS	= lexer.o
PROG	= scc

all:		$(PROG)

$(PROG):	$(OBJS)
		$(CC) -o $(PROG) $(LDFLAGS) $(OBJS) $(LIBS)

clean:;		@rm -f $(PROG) core logfile *.o
