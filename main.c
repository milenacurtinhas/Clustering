#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "vertex.h"
#include "kruskal.h"
#include "reading.h"
#include "graph.h"
#include "stack.h"
#include "dfs.h"

void launch(Vector graph)
{
    for (int i = 0; i < vector_size(graph); i++)
    {
        Node n = *(Node *)vector_at(graph, i);

        // Se o node já foi visitado, significa que já faz parte de outro grupo.
        if (node_get_visited(n))
        {
            continue;
        }
        // Se não foi visitado, então precisa percorrer o grafo
        dfs(graph, n, stdout);
    }
}

int k = 3;

int main(int argc, char *argv[])
{
    Vector vertexes = vector_init(50, sizeof(Vertex));
    int dimensity = read_file(argv[1], vertexes);

    vector_sort(vertexes, vertex_compare_idx);

    for (int i = 0; i < vector_size(vertexes); i++)
    {
        Vertex cur_v = *(Vertex *)(vector_at(vertexes, i));
        vertex_set_id(cur_v, i);
    }

    Vector edges = vector_init(50, sizeof(Edge));

    for (int i = 0; i < vector_size(vertexes); i++)
    {
        Vertex x = *(Vertex *)vector_at(vertexes, i);
        for (int j = i + 1; j < vector_size(vertexes); j++)
        {
            Vertex y = *(Vertex *)vector_at(vertexes, j);
            // inicializa arestas
            Edge e = edge_init(x, y, dimensity);
            vector_push(edges, &e);
        }
    }

    // inicializa vetor da MST
    Vector MST = kruskal(vertexes, edges);

    vector_pop(MST, k - 1);

    Vector graph = graph_build(MST, vertexes);
    launch(graph);

    // for (int i = 0; i < vector_size(MST); i++)1
    //{
    //     Edge e = *(Edge *)vector_at(MST, i);
    //     Vertex v1 = edge_vertex1(e);
    //     Vertex v2 = edge_vertex2(e);
    //     printf("%s - %s\n", vertex_get_name(v1), vertex_get_name(v2));
    // }

    // print_graph(graph);

    // destroi arestas e vértices
    for (int i = 0; i < vector_size(edges); i++)
    {
        Edge e = *(Edge *)vector_at(edges, i);
        edge_destroy(e);
    }

    vector_destroy(edges);

    for (int i = 0; i < vector_size(vertexes); i++)
    {
        Vertex v = *(Vertex *)vector_at(vertexes, i);

        vertex_destroy(v);
    }
    vector_destroy(vertexes);
    vector_destroy(MST);
    graph_destroy(graph);

    return 0;
}