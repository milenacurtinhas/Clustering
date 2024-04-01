#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _quick_union{
    int *id;  //id[i], onde i é o mesmo id do vértice
    int size; //quantidade de vértices
} *QU;

QU QU_init(int N);
void QU_union(QU qu, int p, int q);
int QU_find(QU qu, int p);
bool QU_connected(QU qu, int p, int q);
void QU_destroy(QU qu);

#endif