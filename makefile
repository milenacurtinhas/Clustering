CC = gcc
CFLAGS = -I./include -Wall 
LIBS := -lm
OBJDIR = objects
SRCDIR = src

OBJECTS = $(OBJDIR)/edge.o $(OBJDIR)/kruskal.o $(OBJDIR)/quick-union.o $(OBJDIR)/vector.o $(OBJDIR)/vertex.o $(OBJDIR)/reading.o
ALL_OBJECTS = $(shell find . -type f -name "*.o" -print) 

all: trab1

$(OBJDIR):
	mkdir -p $(OBJDIR)
	
trab1: $(OBJDIR) $(OBJECTS) main.c
	$(CC) $(CFLAGS) -o trab1 main.c $(OBJECTS) $(LIBS)

$(OBJDIR)/edge.o: $(SRCDIR)/edge.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/edge.c -o $(OBJDIR)/edge.o

$(OBJDIR)/kruskal.o: $(SRCDIR)/kruskal.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/kruskal.c -o $(OBJDIR)/kruskal.o

$(OBJDIR)/quick-union.o: $(SRCDIR)/quick-union.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/quick-union.c -o $(OBJDIR)/quick-union.o

$(OBJDIR)/vector.o: $(SRCDIR)/vector.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/vector.c -o $(OBJDIR)/vector.o

$(OBJDIR)/vertex.o: $(SRCDIR)/vertex.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/vertex.c -o $(OBJDIR)/vertex.o

$(OBJDIR)/reading.o: $(SRCDIR)/reading.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/reading.c -o $(OBJDIR)/reading.o

clean:

	rm -f trab1 $(OBJDIR)/*.o 
	rm -rf $(OBJDIR)
	rm -f *.bin
	rm -f *.txt