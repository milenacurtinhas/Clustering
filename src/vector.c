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

    vector->data = calloc(initial_cap, size_of_member);
    vector->size = 0;
    vector->size_of_member = size_of_member;
    vector->allocated = initial_cap;

    return vector;
}

Vector vector_static_init(int initial_cap, int size_of_member)
{
    Vector vector = malloc(sizeof(struct _vector));

    vector->data = calloc(initial_cap, size_of_member);
    vector->size = initial_cap;
    vector->size_of_member = size_of_member;
    vector->allocated = initial_cap;

    return vector;
}

void *vector_at(Vector vector, int index)
{
    if (index >= vector->allocated)
    {
        return NULL;
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

void vector_push_at(Vector vector, void *data, int index)
{
    if (index >= vector->allocated)
    {
        printf("Error: vector_push_at: invalid index %d for vector with size %d.\n", index, vector->size);
        exit(0);
    }
    memcpy(vector->data + index * vector->size_of_member, data, vector->size_of_member);

    //não devia incrementar o tamanho aqui?
    vector->size++;
}

void vector_pop(Vector vector, int k)
{
    // não removi apenas mudei o tamanho do vetor pra não acessar os últimos
    vector->size = vector->size - k;
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