#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "vector.h"
#include "vertex.h"

typedef struct _node *Node;
typedef int (*graph_compare)(const void *, const void *);

/**
 * @brief Constrói um grafo a partir de um vetor de arestas e um vetor de vértices. 
 * O(N+M), sendo N a quantidade de vértices e M a quantidade de arestas
 * 
 * @param edges Vetor de arestas
 * @param vertexes Vetor de vértices
 * @return Vetor do grafo
 */
Vector graph_build(Vector edges, Vector vertexes);

/**
 * @brief Libera a memória alocada pelo grafo
 * 
 * @param graph Grafo a ser liberado
 */
void graph_destroy(Vector graph);

/**
 * @brief Inicializa um nó
 * 
 * @param vertex Vértice do nó
 * @return Nó inicializado
 */
Node node_init(Vertex vertex);

/**
 * @brief Adiciona um nó adjacente ao nó
 * 
 * @param node Nó
 * @param id ID do nó adjacente
 */
void node_add_adjacent(Node node, int id);

/**
 * @brief Define o nó como visitado
 * 
 * @param node Nó
 */
void node_set_visited(Node node);

/**
 * @brief Verifica se o nó foi visitado
 * 
 * @param node Nó
 * @return true Se o nó foi visitado
 * @return false Se o nó não foi visitado
 */
bool node_get_visited(Node node);

/**
 * @brief Retorna o vértice do nó
 * 
 * @param node Nó
 * @return Vértice do nó
 */
Vertex node_get_vertex(Node node);

/**
 * @brief Retorna os nós adjacentes ao nó
 * 
 * @param node Nó
 * @return Vetor de nós adjacentes
 */
Vector node_get_adjacent(Node node);

/**
 * @brief Libera a memória alocada pelo nó
 * 
 * @param node Nó a ser liberado
 */
void node_destroy(Node node);

/**
 * @brief Imprime o grafo
 * 
 * @param graph Grafo a ser impresso
 */
void print_graph(Vector graph);

#endif