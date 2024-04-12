#ifndef QUICK_UNION_BALUDO_H
#define QUICK_UNION_BALUDO_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _quick_union_baludo *QUB;

QUB QUB_init(int N);
void QUB_union(QUB qub, int p, int q);
int QUB_find(QUB qub, int p);
bool QUB_connected(QUB qub, int p, int q);
void QUB_destroy(QUB qub);

#endif