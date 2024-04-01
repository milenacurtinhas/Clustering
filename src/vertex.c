#include "vertex.h"

Vertex vertex_init(char *name, int id, double *coordinates){
    Vertex v = (Vertex)malloc(sizeof(Vertex));

    v->name = name;
    v->id = id;
    v->coordinates = coordinates;

    return v;
}

int vertex_get_id(Vertex v){
    return v->id;
}

char *vertex_get_name(Vertex v){
    return v->name;
}

double vertex_distance(Vertex v1, Vertex v2, int m){
    double sum = 0;

    for(int i = 0; i < m; i++){
        sum += pow(v1->coordinates[i] - v2->coordinates[i], 2);
    }
    
    return sqrt(sum);
}

void vertex_destroy(Vertex Vertex){
    free(Vertex->name);
    free(Vertex->coordinates);
    free(Vertex);
}