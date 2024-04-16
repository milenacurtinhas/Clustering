#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _quick_union *QU;

/**
 * @brief Inicializa a estrutura de dados Quick Union
 * 
 * @param N Número de elementos
 * @return Estrutura de dados Quick Union
 */
QU QU_init(int N);

/**
 * @brief Realiza a união dos conjuntos de p e q
 * 
 * @param qu Estrutura de dados Quick Union
 * @param p Elemento p
 * @param q Elemento q
 */
void QU_union(QU qu, int p, int q);

/**
 * @brief Encontra o conjunto de p
 * 
 * @param qu Estrutura de dados Quick Union
 * @param p Elemento p
 * @return Conjunto de p
 */
int QU_find(QU qu, int p);

/**
 * @brief Verifica se p e q estão conectados
 * 
 * @param qu Estrutura de dados Quick Union
 * @param p Elemento p
 * @param q Elemento q
 * @return true Se p e q estão conectados
 * @return false Se p e q não estão conectados
 */
bool QU_connected(QU qu, int p, int q);

/**
 * @brief Libera a memória alocada pela estrutura de dados Quick Union
 * 
 * @param qu Estrutura de dados Quick Union
 */
void QU_destroy(QU qu);

#endif