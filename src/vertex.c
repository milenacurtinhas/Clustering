#include "vertex.h"

struct _vertex
{
    char *name;
    int id;
    double *coordinates;
};

Vertex vertex_init(char *name, double *coordinates)
{
    Vertex v = (Vertex)malloc(sizeof(struct _vertex));

    v->name = name;
    v->id = 0;
    v->coordinates = coordinates;

    return v;
}

int vertex_get_id(Vertex v)
{
    return v->id;
}

char *vertex_get_name(Vertex v)
{
    return v->name;
}

double *vertex_get_coordinates(Vertex v){
    return v->coordinates;
}

double vertex_distance(Vertex v1, Vertex v2, int m)
{
    double sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum += pow(v1->coordinates[i] - v2->coordinates[i], 2.0);
    }

    return sqrt(sum);
}

void vertex_destroy(Vertex Vertex)
{
    free(Vertex->name);
    free(Vertex->coordinates);
    free(Vertex);
}