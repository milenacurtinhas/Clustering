#ifndef VECTOR_H
#define VECTOR_H

#include "edge.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _vector *Vector;
typedef int (*vector_compare)(const void *, const void *);

Vector vector_init(int initial_cap, int sizeof_member);
void *vector_at(Vector vector, int index);
void vector_push(Vector vector, void *data);
void vector_sort(Vector vector, vector_compare cmp);
int vector_size(Vector vector);
void vector_destroy(Vector vector);

#endif