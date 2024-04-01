#include "edge.h"

Edge edge_init(Vertex vertex1, Vertex vertex2, int m){
    Edge edge = (Edge)malloc(sizeof(Edge));
    
    edge->dist = vertex_distance(vertex1, vertex2, m);
    edge->vertex1 = vertex1;
    edge->vertex2 = vertex2;

    return edge;
}

double edge_distance(Edge edge){
    return edge->dist;
}

Vertex edge_vertex1(Edge edge){
    return edge->vertex1;
}

Vertex edge_vertex2(Edge edge){
    return edge->vertex2;
}

void edge_destroy(Edge edge){
    //chama a função de liberar o vertex daqui?
    free(edge);
}