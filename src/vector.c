#include "vector.h"

Vector vector_init(int initial_cap, int sizeof_member){
    Vector vector = malloc(initial_cap * sizeof(Vector));
    vector->data = calloc(initial_cap, sizeof(data_type));
    vector->size = 0;
    vector->allocated = initial_cap;

    return vector;
}

data_type vector_at(Vector vector, int index){
    if (index >= vector->size || index < 0){
        printf("Error: vector_get: invalid index %d for vector with size %d.\n", index, vector->size);
        exit(0);
    }

    return vector->data[index];
}

void vector_push(Vector vector, data_type *data){
    //decidir se o realloc vai ser multiplicar o antigo por 2 ou adicionar um valor fixo
    if (vector->size == vector->allocated){
        vector->allocated *= 2;
        vector = realloc(vector, vector->allocated * sizeof(data_type));
    }

    vector[vector->size].data = data;
    vector->size++;
}


void vector_sort(Vector vector){
    //implementar o quicksort
}

int vector_size(Vector vector){
    return vector->size;
}

void vector_destroy(Vector vector){
    //chama o edge_destroy daqui?
    free(vector);
}