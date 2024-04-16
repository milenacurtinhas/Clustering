#ifndef VERTEX_H
#define VERTEX_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _vertex *Vertex;

/**
 * @brief Inicializa vértice
 * 
 * @param name Nome do vértice
 * @param coordinates Array de coordenadas
 * @return Vértice inicializado
 */
Vertex vertex_init(char *name, double *coordinates);

/**
 * @brief Define o id do vértice
 * 
 * @param v Vértice a ser modificado
 * @param id Id a ser definido
 */
void vertex_set_id(Vertex v, int id);

/**
 * @brief Retorna o id do vértice
 * 
 * @param v Vértice a ser consultado
 * @return Id do vértice
 */
int vertex_get_id(Vertex v);

/**
 * @brief Retorna o nome do vértice
 * 
 * @param v Vértice a ser consultado
 * @return Nome do vértice
 */
char *vertex_get_name(Vertex v);

/**
 * @brief Retorna as coordenadas do vértice
 * 
 * @param v Vértice a ser consultado
 * @return Coordenadas do vértice
 */
double *vertex_get_coordinates(Vertex v);

/**
 * @brief Calcula a distância entre dois vértices
 * 
 * @param v1 Vértice 1
 * @param v2 Vértice 2
 * @param m Dimensão dos vértices
 * @return Distância entre os vértices
 */
double vertex_distance(Vertex v1, Vertex v2, int m);

/**
 * @brief Compara dois vértices pelo nome
 * 
 * @param a Vértice 1
 * @param b Vértice 2
 * @return Resultado da comparação
 */
int vertex_compare_name(const void *a, const void *b);

/**
 * @brief Libera memória alocada para o vértice
 * 
 * @param Vertex Vértice a ser liberado
 */
void vertex_destroy(Vertex Vertex);

#endif