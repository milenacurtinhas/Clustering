#include "edge.h"

struct _edge {
    double dist;
    Vertex vertex1;
    Vertex vertex2;
};

int edge_compare(const void *a, const void *b) {
    const Edge a1 = *(Edge *)a;
    const Edge a2 = *(Edge *)b;
    double diff = a1->dist - a2->dist;
    if (diff > 0)
        return 1;
    else
        return -1;
}

Edge edge_init(Vertex vertex1, Vertex vertex2, int m) {
    Edge edge = (Edge)malloc(sizeof(struct _edge));

    edge->dist = vertex_distance(vertex1, vertex2, m);
    edge->vertex1 = vertex1;
    edge->vertex2 = vertex2;

    return edge;
}

double edge_distance(Edge edge) {
    return edge->dist;
}

Vertex edge_vertex1(Edge edge) {
    return edge->vertex1;
}

Vertex edge_vertex2(Edge edge) {
    return edge->vertex2;
}

void edge_destroy(Edge edge) {
    free(edge);
}