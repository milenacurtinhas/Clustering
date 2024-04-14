#include "vector.h"

#include <string.h>

struct _vector {
    char *data;
    size_t size;
    size_t allocated;
    size_t size_of_member;
};

Vector vector_init(size_t initial_cap, size_t size_of_member) {
    Vector vector = malloc(sizeof(struct _vector));

    vector->data = calloc(initial_cap, size_of_member);
    vector->size = 0;
    vector->size_of_member = size_of_member;
    vector->allocated = initial_cap;

    return vector;
}

Vector vector_static_init(size_t initial_cap, size_t size_of_member) {
    Vector vector = malloc(sizeof(struct _vector));

    vector->data = calloc(initial_cap, size_of_member);
    vector->size = initial_cap;
    vector->size_of_member = size_of_member;
    vector->allocated = initial_cap;

    return vector;
}

void *vector_at(Vector vector, size_t index) {
    if (index >= vector->allocated) {
        return NULL;
    }

    return vector->data + vector->size_of_member * index;
}

void vector_push(Vector vector, void *data) {
    if (vector->size == vector->allocated) {
        vector->allocated *= 2;
        vector->data =
            realloc(vector->data, vector->allocated * vector->size_of_member);
    }
    memcpy(vector->data + vector->size * vector->size_of_member, data,
           vector->size_of_member);
    vector->size++;
}

void vector_set(Vector vector, void *data, size_t index) {
    if (index >= vector->allocated) {
        exit(1);
    }
    memcpy(vector->data + index * vector->size_of_member, data,
           vector->size_of_member);
}

void vector_pop(Vector vector, size_t k) {
    vector->size = vector->size - k;
}

void vector_sort(Vector vector, vector_compare cmp) {
    qsort(vector->data, vector->size, vector->size_of_member, cmp);
}

size_t vector_size(Vector vector) {
    return vector->size;
}

void vector_destroy(Vector vector) {
    free(vector->data);
    free(vector);
}