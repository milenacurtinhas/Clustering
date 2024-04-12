#include "kruskal.h"

Vector kruskal(Vector vertexes, Vector edges) {
    QUB set = QUB_init(vector_size(edges));
    Vector MST = vector_init(100, sizeof(Edge));
    vector_sort(edges, edge_compare);

    for (int i = 0; i < vector_size(edges); i++) {
        Edge e = *(Edge *)vector_at(edges, i);

        Vertex v1 = edge_vertex1(e);
        Vertex v2 = edge_vertex2(e);

        int vertex_id1 = vertex_get_id(v1);
        int vertex_id2 = vertex_get_id(v2);

        if (QUB_find(set, vertex_id1) != QUB_find(set, vertex_id2)) {
            vector_push(MST, &e);
            QUB_union(set, vertex_id1, vertex_id2);
        }
    }

    QUB_destroy(set);

    return MST;
}