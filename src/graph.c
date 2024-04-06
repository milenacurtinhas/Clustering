#include "graph.h"

struct _node
{
    Vertex vertex;
    bool visited;
    Vector adjacent;
};

Vector graph_build(Vector edges, Vector vertexes)
{
    Vector graph = vector_static_init(vector_size(vertexes), sizeof(Node));

    for(int i = 0; i < vector_size(edges); i++){
        Edge e = *(Edge *)vector_at(edges, i);
        Vertex v1 = edge_vertex1(e);
        Vertex v2 = edge_vertex2(e);

        int index1 = vertex_get_id(v1);
        int index2 = vertex_get_id(v2);

        Node n1 = *(Node *)vector_at(graph, index1);
        Node n2 = *(Node *)vector_at(graph, index2);
    
        if(n1 == NULL){
            n1 = node_init(v1);
            vector_push_at(graph, &n1, index1);
        }
        if(n2 == NULL){
            n2 = node_init(v2);
            vector_push_at(graph, &n2, index2);
        }

        node_add_adjacent(n1, index2);
        node_add_adjacent(n2, index1);
    }

    return graph;
}

void graph_destroy(Vector graph)
{
    for(int i = 0; i < vector_size(graph); i++){
        Node n = *(Node *)vector_at(graph, i);
        node_destroy(n);
    }
    vector_destroy(graph);
}

Node node_init(Vertex vertex)
{
    Node node = malloc(sizeof(struct _node));
    node->vertex = vertex;
    node->visited = false;
    node->adjacent = vector_init(100, sizeof(int));
    return node;
}

void node_add_adjacent(Node node, int id)
{
    vector_push(node->adjacent, &id);
}

void node_set_visited(Node node)
{
    node->visited = true;
}

bool node_get_visited(Node node)
{
    return node->visited;
}

Vertex node_get_vertex(Node node)
{
    return node->vertex;
}

Vector node_get_adjacent(Node node)
{
    return node->adjacent;
}

void node_destroy(Node node)
{
    vector_destroy(node->adjacent);
    free(node);
}

void print_graph(Vector graph){
    printf("\nGraph\n");
    
    for(int i = 0; i < vector_size(graph); i++){
        Node n = *(Node *)vector_at(graph, i);
        Vertex v = node_get_vertex(n);
        printf("%s -> ", vertex_get_name(v));
        Vector adj = node_get_adjacent(n);
        for(int j = 0; j < vector_size(adj); j++){
            int id = *(int *)vector_at(adj, j);
            Node n2 = *(Node *)vector_at(graph, id);
            Vertex v2 = node_get_vertex(n2);
            printf("%s ", vertex_get_name(v2));
        }
        printf("\n");
    }
}