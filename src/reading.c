#include "reading.h"

int vertex_dimension(char *line) {
    int result = 0;

    // Conta a quantidade de vírgulas na linha, 
    // visto que as coordenadas são separadas por vírgulas as quantidades são equivalentes
    // A complexidade do algoritmo é O(M), sendo M a quantidade de coordenadas,
    // visto que o laço percorre a linha tantas vezes quanto a quantidade de coornadas
    while (*line) {
        if (*line == ',') result++;
        line++;
    }
    
    return result;
}

// Sendo N a quantidade de vértices (equivalente a quantidade de linhas)
// e M a quantidade de coordenadas (equivalente à dimensão dos vértices),,
// a complexidade do algoritmo é O(M*N) ??(ou seria O(N*M + M), por causa da função de calcular dimensão??
int read_file_of_vertexes(FILE *file, Vector vertexes) {
    char *line = NULL;
    size_t size = 0;
    ssize_t read = getline(&line, &size, file);

    // A complexidade do algoritmo é O(M)
    int dimension = vertex_dimension(line);

    // O while abaixo tem complexidade O(N)
    while (read != -1) {
        double *coordinates = malloc(dimension * sizeof(double));
        char *name = strdup(strtok(line, ",\n"));
        char *ptr, *number_char = strtok(NULL, ",\n");

        int i = 0;

        // O while abaixo tem complexidade O(M)
        while (number_char != NULL) {
            double number = strtod(number_char, &ptr);
            coordinates[i] = number;
            i++;
            number_char = strtok(NULL, ",\n");
        }

        Vertex v = vertex_init(name, coordinates);
        vector_push(vertexes, &v);

        read = getline(&line, &size, file);
    }

    free(line);
    return dimension;
}