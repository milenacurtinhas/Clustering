#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "vector.h"
#include "quick-union.h"
#include "vertex.h"
#include "edge.h"

/**
 * @brief Realiza o algoritmo de Kruskal para gerar a árvore geradora mínima
 * 
 * @param vertexes Vetor de vértices
 * @param edges Vetor de arestas
 * @return Vetor da arvore geradora mínima
 */
Vector kruskal(Vector vertexes, Vector edges);

#endif