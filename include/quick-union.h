#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <stdbool.h>

typedef struct quick_union *QU;

QU QU_init(QU qu, int N);
void QU_union(QU qu, int p, int q);
int QU_find(QU qu, int p);
bool QU_connected(QU qu, int p, int q);

#endif