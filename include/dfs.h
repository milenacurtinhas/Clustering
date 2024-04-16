#ifndef DFS_H
#define DFS_H

#include <stdio.h>

#include "graph.h"
#include "vector.h"

/**
 * @brief Realiza uma busca em profundidade em um grafo
 * 
 * @param graph Grafo
 * @param n Nó inicial
 * @param output Arquivo de saída
 */
void dfs(Vector graph, Node n, FILE *output);

#endif