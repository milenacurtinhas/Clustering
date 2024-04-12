#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"
#include "graph.h"
#include "kruskal.h"
#include "reading.h"
#include "stack.h"
#include "vector.h"
#include "vertex.h"

#define INITIAL_VERTEXES_CAP 1000
#define INITIAL_EDGES_CAP 1000

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("usage: %s <file_in> k <file_out>\n", argv[0]);
        exit(1);
    }

    int k = atoi(argv[2]);

    Vector vertexes = vector_init(INITIAL_VERTEXES_CAP, sizeof(Vertex));
    Vector edges = vector_init(INITIAL_EDGES_CAP, sizeof(Edge));

    int dimension = read_file(argv[1], vertexes);

    vector_sort(vertexes, vertex_compare_idx);
    for (int i = 0; i < vector_size(vertexes); i++) {
        Vertex v1 = *(Vertex *)(vector_at(vertexes, i));
        vertex_set_id(v1, i);
    }

    for (int i = 0; i < vector_size(vertexes); i++) {
        Vertex v1 = *(Vertex *)vector_at(vertexes, i);
        for (int j = i + 1; j < vector_size(vertexes); j++) {
            Vertex v2 = *(Vertex *)vector_at(vertexes, j);
            Edge e1 = edge_init(v1, v2, dimension);
            vector_push(edges, &e1);
        }
    }

    Vector MST = kruskal(vertexes, edges);
    vector_pop(MST, k - 1);
    Vector graph = graph_build(MST, vertexes);

    for (int i = 0; i < vector_size(graph); i++) {
        Node n = *(Node *)vector_at(graph, i);
        if (node_get_visited(n)) continue;
        dfs(graph, n, stdout);
    }

    for (int i = 0; i < vector_size(edges); i++) {
        Edge e1 = *(Edge *)vector_at(edges, i);
        edge_destroy(e1);
    }

    for (int i = 0; i < vector_size(vertexes); i++) {
        Vertex v1 = *(Vertex *)vector_at(vertexes, i);
        vertex_destroy(v1);
    }

    vector_destroy(edges);
    vector_destroy(vertexes);
    vector_destroy(MST);
    graph_destroy(graph);

    return 0;
}