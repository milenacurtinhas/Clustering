#include "kruskal.h"

Vector kruskal(Vector vertexes, Vector edges) {
    QU set = QU_init(vector_size(vertexes));
    Vector MST = vector_init(100, sizeof(int));

    // O(M), sendo M a quantidade de arestas
    for (int i = 0; i < vector_size(edges); i++) {
        EdgeStruct *e = (EdgeStruct *)vector_at(edges, i);

        int idx_v1 = (int)e->id/vector_size(vertexes);
        int idx_v2 = (e->id - idx_v1 * vector_size(vertexes));

        Vertex v1 = *(Vertex*)vector_at(vertexes, idx_v1);
        Vertex v2 = *(Vertex*)vector_at(vertexes, idx_v2);

        int vertex_id1 = vertex_get_id(v1);
        int vertex_id2 = vertex_get_id(v2);

        if (QU_find(set, vertex_id1) != QU_find(set, vertex_id2)) {
            // push e quick union são executados no pior caso O(M) e no melhor caso O(?). 
            vector_push(MST, &e->id);
            QU_union(set, vertex_id1, vertex_id2);
        }     
    }

    QU_destroy(set);

    return MST;
}