CC = gcc
CFLAGS = -I./include -Wall -O2 -g
LIBS := -lm
OBJDIR = objects
SRCDIR = src

OBJECTS = $(OBJDIR)/edge.o $(OBJDIR)/kruskal.o $(OBJDIR)/quick-union.o $(OBJDIR)/vector.o $(OBJDIR)/vertex.o $(OBJDIR)/graph.o $(OBJDIR)/stack.o $(OBJDIR)/reading.o $(OBJDIR)/dfs.o
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

$(OBJDIR)/graph.o: $(SRCDIR)/graph.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/graph.c -o $(OBJDIR)/graph.o

$(OBJDIR)/stack.o: $(SRCDIR)/stack.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/stack.c -o $(OBJDIR)/stack.o

$(OBJDIR)/reading.o: $(SRCDIR)/reading.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/reading.c -o $(OBJDIR)/reading.o

$(OBJDIR)/dfs.o: $(SRCDIR)/dfs.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/dfs.c -o $(OBJDIR)/dfs.o

clean:

	rm -f trab1 $(OBJDIR)/*.o 
	rm -rf $(OBJDIR)
	rm -f *.bin
	rm -f *.txt