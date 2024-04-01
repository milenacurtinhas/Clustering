#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"
#include "quick-union.h"
#include <stdlib.h>

typedef struct _edge {
    double dist;
    Vertex vertex1;
    Vertex vertex2;
} *Edge;

// Calcula a distância e armazena na estrtura.
Edge edge_init(Vertex vertex1, Vertex vertex2, int m);
double edge_distance(Edge edge);
Vertex edge_vertex1(Edge edge);
Vertex edge_vertex2(Edge edge);

// Só da free no edge e nao no vertex;
void edge_destroy(Edge edge);

#endif