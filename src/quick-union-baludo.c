#include "quick-union-baludo.h"

struct _quick_union_baludo {
    int *id;
    int size;
    int *sz;    // número de objetos da árvore com raiz em i
};

QUB QUB_init(int size) {
    QUB qub = (QUB)malloc(sizeof(struct _quick_union_baludo));
    qub->id = (int *)malloc(size * sizeof(int));
    qub->sz = (int *)malloc(size * sizeof(int));

    qub->size = size;
    for (int i = 0; i < size; i++) {
        qub->id[i] = i;
        qub->sz[i] = 1;
    }

    return qub;
}

void QUB_union(QUB qub, int p, int q) {
    int i = QUB_find(qub, p); // Pendure a arvore menor sob a maior.
    int j = QUB_find(qub, q); // Profundidade de ? acessos.

    if (i == j) return;

    if (qub->sz[i] < qub->sz[j]) { 
        qub->id[i] = j; 
        qub->sz[j] += qub->sz[i]; 
    }
    else { 
        qub->id[j] = i; 
        qub->sz[i] += qub->sz[j]; 
    }
}

int QUB_find(QUB qub, int p) {
    while (p != qub->id[p]) {
        qub->id[p] = qub->id[qub->id[p]];  // Uma unica linha de codigo adicional.
        p = qub->id[p];                  // Cada passo agora requer 5 acessos.
    }
    return p;
}

bool QUB_connected(QUB qub, int p, int q) {
    return QUB_find(qub, p) == QUB_find(qub, q);
}

void QUB_destroy(QUB qub) {
    free(qub->id);
    free(qub->sz);
    free(qub);
}