#include "quick-union.h"

struct _quick_union {
    int *id;   // id[i], onde i é o mesmo id do vértice
    int size;  // quantidade de vértices
};

QU QU_init(int size) {
    QU qu = (QU)malloc(sizeof(struct _quick_union));
    qu->id = (int *)malloc(size * sizeof(int));

    qu->size = size;
    for (int i = 0; i < size; i++) {
        qu->id[i] = i;
    }

    return qu;
}

void QU_union(QU qu, int p, int q) {
    int i = QU_find(qu, p);  // Modifique raiz de p para a raiz de q.
    int j = QU_find(qu, q);  // Profundidade de p+q acessos.
    qu->id[i] = j;
}

int QU_find(QU qu, int p) {
    while (p != qu->id[p]) {
        qu->id[p] = qu->id[qu->id[p]];  // Uma unica linha de codigo adicional.
        p = qu->id[p];                  // Cada passo agora requer 5 acessos.
    }
    return p;
}

bool QU_connected(QU qu, int p, int q) {
    return QU_find(qu, p) == QU_find(qu, q);
}

void QU_destroy(QU qu) {
    free(qu->id);
    free(qu);
}