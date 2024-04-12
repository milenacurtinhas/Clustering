#include "vertex.h"

#include <stdio.h>
#include <string.h>

struct _vertex {
    char *name;
    int id;
    double *coordinates;
};

Vertex vertex_init(char *name, double *coordinates) {
    Vertex v = (Vertex)malloc(sizeof(struct _vertex));

    v->name = name;
    v->id = 0;
    v->coordinates = coordinates;

    return v;
}

void vertex_set_id(Vertex v, int id) {
    v->id = id;
}

int vertex_get_id(Vertex v) {
    return v->id;
}

char *vertex_get_name(Vertex v) {
    return v->name;
}

double *vertex_get_coordinates(Vertex v) {
    return v->coordinates;
}

double vertex_distance(Vertex v1, Vertex v2, int m) {
    double sum = 0;
    for (int i = 0; i < m; i++)
        sum += pow(v1->coordinates[i] - v2->coordinates[i], 2.0);
    return sqrt(sum);
}

int vertex_compare_idx(const void *a, const void *b) {
    const Vertex a1 = *(Vertex *)a;
    const Vertex a2 = *(Vertex *)b;
    return strcmp(vertex_get_name(a1), vertex_get_name(a2));
}

void vertex_destroy(Vertex Vertex) {
    free(Vertex->name);
    free(Vertex->coordinates);
    free(Vertex);
}