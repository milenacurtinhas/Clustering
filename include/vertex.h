#ifndef VERTEX_H
#define VERTEX_H

#include <stdlib.h>
#include <math.h>

typedef struct _vertex *Vertex;

Vertex vertex_init(char *name, double *coordinates);
int vertex_get_id(Vertex v);
char *vertex_get_name(Vertex v);
double *vertex_get_coordinates(Vertex v);
double vertex_distance(Vertex v1, Vertex v2, int m);
void vertex_destroy(Vertex Vertex);

#endif