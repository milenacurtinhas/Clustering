#ifndef EDGE_H
#define EDGE_H

#include <stdlib.h>

#include "vertex.h"

typedef struct {
    double dist;
    int id;
} EdgeStruct;

int edge_cmp(const void *a, const void *b);

#endif