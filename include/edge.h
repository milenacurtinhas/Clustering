#ifndef EDGE_H
#define EDGE_H

#include <stdlib.h>

typedef struct {
    double dist;
    int id;
} EdgeStruct;

/**
 * @brief Compara duas arestas pela distância.
 * 
 * @param a Aresta 1
 * @param b Aresta 2
 * @return 1 se a > b, -1 se a <= b
 */
int edge_cmp(const void *a, const void *b);

#endif