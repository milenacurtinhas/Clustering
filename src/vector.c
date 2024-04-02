#include "vector.h"
#include <string.h>

struct _vector
{
    char *data;
    int size;
    int allocated;
    int size_of_member;
};

Vector vector_init(int initial_cap, int size_of_member)
{
    Vector vector = malloc(sizeof(struct _vector));

    vector->data = malloc(initial_cap * size_of_member);
    vector->size = 0;
    vector->size_of_member = size_of_member;
    vector->allocated = initial_cap;

    return vector;
}

void *vector_at(Vector vector, int index)
{
    if (index >= vector->size || index < 0)
    {
        printf("Error: vector_get: invalid index %d for vector with size %d.\n", index, vector->size);
        exit(0);
    }

    return vector->data + vector->size_of_member * index;
}

void vector_push(Vector vector, void *data)
{
    if (vector->size == vector->allocated)
    {
        vector->allocated *= 2;
        vector->data = realloc(vector->data, vector->allocated * vector->size_of_member);
    }
    memcpy(vector->data + vector->size * vector->size_of_member, data, vector->size_of_member);
    vector->size++;
}

void vector_sort(Vector vector, vector_compare cmp)
{
    qsort(vector->data, vector->size, vector->size_of_member, cmp);
}

int vector_size(Vector vector)
{
    return vector->size;
}

void vector_destroy(Vector vector)
{
    free(vector->data);
    free(vector);
}