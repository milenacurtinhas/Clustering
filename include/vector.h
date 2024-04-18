#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edge.h"

typedef struct _vector *Vector;
typedef int (*vector_compare)(const void *, const void *);

/**
 * @brief Inicializa um vetor de tamanho dinâmico
 * 
 * @param initial_cap Capacidade inicial do vetor
 * @param size_of_member Tamanho do membro do vetor
 * @return Vector inicializado
 */
Vector vector_init(size_t initial_cap, size_t size_of_member);

/**
 * @brief Inicializa um vetor de tamanho estático
 * 
 * @param initial_cap Capacidade do vetor
 * @param size_of_member Tamanho do membro do vetor
 * @return Vector inicializado
 */
Vector vector_static_init(size_t initial_cap, size_t size_of_member);

/**
 * @brief Retorna conteúdo do vetor na posição desejada
 * 
 * @param vector Vetor com o conteúdo desejado
 * @param index Posição desejada
 * @return Ponteiro void para o conteúdo encontrado no índice dado
 */
void *vector_at(Vector vector, size_t index);

/**
 * @brief Adiciona um elemento ao final do vetor.
 * 
 * @param vector Vetor a ser adicionado o elemento
 * @param data Conteúdo a ser adicionado
 */
void vector_push(Vector vector, void *data);

/**
 * @brief Adiciona um elemento em uma posição arbitrário do vetor
 * 
 * @param vector Vetor a ser adicionado o elemento
 * @param data Conteúdo a ser adicionado
 * @param index Posição a ser adicionado o elemento
 */
void vector_set(Vector vector, void *data, size_t index);

/**
 * @brief Diminui o tamanho do vetor
 * 
 * @param vector Vetor a ser diminuido
 * @param k quantidade de elementos a serem descartados
 */
void vector_pop(Vector vector, size_t k);

/**
 * @brief Realiza qsort da biblioteca C no vetor
 * 
 * @param vector Vetor a ser organizado
 * @param cmp Função de comparação usada para organizar o vetor
 */
void vector_sort(Vector vector, vector_compare cmp);

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param vector Vetor a ser verificado o tamanho
 * @return Tamanho do vetor
 */
size_t vector_size(Vector vector);

/**
 * @brief Libera a memória alocada pelo vetor
 * 
 * @param vector Vetor a ser liberado
 */
void vector_destroy(Vector vector);

#endif