#include "kruskal.h"

Vector kruskal(Vector vertexes, Vector edges) {
    QU set = QU_init(vector_size(edges));
    Vector MST = vector_init(100, sizeof(Edge));
    vector_sort(edges, edge_compare);

    for (int i = 0; i < vector_size(edges); i++) {
        Edge e = *(Edge *)vector_at(edges, i);

        Vertex v1 = edge_vertex1(e);
        Vertex v2 = edge_vertex2(e);

        int vertex_id1 = vertex_get_id(v1);
        int vertex_id2 = vertex_get_id(v2);

        if (QU_find(set, vertex_id1) != QU_find(set, vertex_id2)) {
            vector_push(MST, &e);
            QU_union(set, vertex_id1, vertex_id2);
        }
    }

    QU_destroy(set);

    return MST;
}