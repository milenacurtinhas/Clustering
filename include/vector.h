#ifndef VECTOR_H
#define VECTOR_H

typedef struct _vector *Vector;

Vector vector_init(int initial_cap, int sizeof_member);
void *vector_at(Vector vector, int index);
void vector_push(Vector vector, void *data);
void vector_sort(Vector vector);
int vector_size(Vector vector);
void vector_free(Vector vector);

#endif