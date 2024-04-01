#include "kruskal.h"

void kruskal(Vector vertexes, Vector edges)
{
    QU set = QU_init(vector_size(edges));
    vector_sort(edges);
    int i;
    for (i = 0; i < vector_size(edges); i++)
    {
        Edge e = (Edge)vector_at(edges, i);
        Vertex v1 = edge_vertex1(e);
        Vertex v2 = edge_vertex2(e);
        int vertex_id1 = vertex_get_id(v1);
        int vertex_id2 = vertex_get_id(v2);
        if (QU_find(set, vertex_id1) != QU_find(set, vertex_id2))
        {
            // Fazer o conjunto da arvore geradora minima
            QU_union(set, vertex_id1, vertex_id2);
        }
    }
}