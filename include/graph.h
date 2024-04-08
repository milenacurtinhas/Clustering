#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <string.h>
#include "vertex.h"
#include "vector.h"

typedef struct _node *Node;
typedef int (*graph_compare)(const void *, const void *);

Vector graph_build(Vector edges, Vector vertexes);
void graph_destroy(Vector graph);
void graph_sort(Vector graph);
Node node_init(Vertex vertex);
void node_add_adjacent(Node node, int id);
void node_set_visited(Node node);
bool node_get_visited(Node node);
Vertex node_get_vertex(Node node);
Vector node_get_adjacent(Node node);
void node_destroy(Node node);
void print_graph(Vector graph);

#endif