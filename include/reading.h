#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "quick-union.h"
#include "vector.h"
#include "vertex.h"

/**
 * @brief Conta as coordenadas de um vértice para saber a dimensão deles
 * 
 * @param line linha do arquivo contendo as coordenadas dos vértices
 * @return dimensão dos vértices 
 */
int vertex_dimension(char *line);

/**
 * @brief Lê um arquivo contendo os vértices de um grafo e guarda as informações no vetor de vértices
 * 
 * @param file arquivo a ser lido
 * @param vertexes vetor de vértices inicializado
 * @return dimensão dos vértices
 */
int read_file_of_vertexes(FILE* file, Vector vertexes);

#endif