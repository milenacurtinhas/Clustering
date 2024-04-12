#ifndef VERTEX_H
#define VERTEX_H

#include <stdlib.h>
#include <math.h>

typedef struct _vertex *Vertex;

Vertex vertex_init(char *name, double *coordinates);
void vertex_set_id(Vertex v, int id);
int vertex_get_id(Vertex v);
char *vertex_get_name(Vertex v);
double *vertex_get_coordinates(Vertex v);
double vertex_distance(Vertex v1, Vertex v2, int m);
void vertex_show(Vertex v);
int vertex_compare_idx(const void *a, const void *b);
void vertex_destroy(Vertex Vertex);

#endif