#include "quick-union-baludo.h"

struct _quick_union_baludo {
    int *id;
    int size;
};

QUB QUB_init(int size) {
    QUB qub = (QUB)malloc(sizeof(struct _quick_union_baludo));
    qub->id = (int *)malloc(size * sizeof(int));

    return qub;
}

void QUB_union(QUB qub, int p, int q) {
}

int QUB_find(QUB qub, int p) {
    return 1;
}

bool QUB_connected(QUB qub, int p, int q) {
    return true;
}

void QUB_destroy(QUB qub) {
    free(qub->id);
    free(qub);
}