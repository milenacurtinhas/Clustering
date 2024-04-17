#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"
#include "edge.h"
#include "graph.h"
#include "kruskal.h"
#include "reading.h"
#include "stack.h"
#include "vector.h"
#include "vertex.h"

// Evita realloc
#define INITIAL_VERTEXES_CAP 30010

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("usage: %s <file_in> k <file_out>\n", argv[0]);
        exit(1);
    }

    int k = atoi(argv[2]);
    FILE *input = fopen(argv[1], "r");

    if (!input) {
        printf("error: canot open file\n");
        exit(1);
    }

    Vector vertexes = vector_init(INITIAL_VERTEXES_CAP, sizeof(Vertex));

    int dimension = read_file_of_vertexes(input, vertexes);
    fclose(input);

    size_t vertexes_size = vector_size(vertexes);

    if(k < 0){
        printf("error: number of edges to be removed must be zero or greater than zero\n");
        exit(1);
    }

    if(k > vertexes_size){
        printf("error: number of edges to be removed greater than number of existing edges\n");
        exit(1);
    }

    vector_sort(vertexes, vertex_compare_name);

    // O(N), sendo N a quantidade de vértices
    for (int i = 0; i < vector_size(vertexes); i++) {
        Vertex v1 = *(Vertex *)(vector_at(vertexes, i));
        vertex_set_id(v1, i);
    }

    size_t edges_size = ((vertexes_size) * (vertexes_size - 1) / 2);
    Vector edges = vector_init(edges_size, sizeof(EdgeStruct));

    int cont = 0;

    //O(N^2), sendo N a quantidade de vértices
    for (int i = 0; i < vector_size(vertexes); i++) {
        Vertex v1 = *(Vertex *)vector_at(vertexes, i) ;
        int mult = vector_size(vertexes) * (i + 1) + i;
        
        for (int j = i + 1; j < vector_size(vertexes); j++) {
            Vertex v2 = *(Vertex *)vector_at(vertexes, j);
            double dist = vertex_distance(v1, v2, dimension);

            EdgeStruct edge = (EdgeStruct){
                .dist = dist,
                .id =mult,
            };
            
            vector_push(edges, &edge);   
            mult += vector_size(vertexes);
            cont++;
        }
    }

    vector_sort(edges, edge_cmp);

    Vector MST = kruskal(vertexes, edges);
    vector_pop(MST, k - 1);

    Vector graph = graph_build(MST, vertexes);

    FILE *output = fopen(argv[3], "w");

    //O(N)
    for (int i = 0; i < vector_size(graph); i++) {
        Node n = *(Node *)vector_at(graph, i);
        if (node_get_visited(n)) continue;
        //pior caso: O(N), melhor caso: O(1?)
        dfs(graph, n, output);
    }

    fclose(output);

    //O(N)
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
