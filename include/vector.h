#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#include "edge.h"

typedef struct _vector *Vector;
typedef int (*vector_compare)(const void *, const void *);

Vector vector_init(size_t initial_cap, size_t sizeof_member);
Vector vector_static_init(size_t initial_cap, size_t size_of_member);
void *vector_at(Vector vector, size_t index);
void vector_push(Vector vector, void *data);
void vector_set(Vector vector, void *data, size_t index);
void vector_pop(Vector vector, size_t k);
void vector_sort(Vector vector, vector_compare cmp);
size_t vector_size(Vector vector);
void vector_destroy(Vector vector);

#endif