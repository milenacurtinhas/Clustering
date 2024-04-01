#ifndef VECTOR_H
#define VECTOR_H

#include "edge.h"
#include <stdio.h>
#include <stdlib.h>

typedef Edge data_type;

typedef struct
{
    data_type *data;
    int size;
    int allocated;
} *Vector;


Vector vector_init(int initial_cap, int sizeof_member);
data_type vector_at(Vector vector, int index);
void vector_push(Vector vector, data_type *data);
void vector_sort(Vector vector);
int vector_size(Vector vector);
void vector_destroy(Vector vector);

#endif