#include "reading.h"
#include "vertex.h"
#include <stdio.h>
#include <unistd.h>

void read_file(const char* filename, Vector vertexes)
{
    double *coordenates = calloc(50, sizeof(double));
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    ssize_t line_size = 0;

    FILE *file = fopen(filename, "r");
    if (!file){
        printf("ERROR: couldn't find the file given!\n");
    }

    /* Loop through until we are done with the file. */
    line_size = getline(&line_buf, &line_buf_size, file);
    while (line_size >= 0)
    {
        char * name = strdup(strtok(line_buf, ",\n"));
        printf("%s: ", name);

        char *ptr, *number_char = strtok(NULL, ",\n");
        int i = 0;
        while (number_char != NULL){

            double number = strtod(number_char, &ptr);
            coordenates[i] = number;
            printf("%lf, ", number);

            i++;

            number_char = strtok(NULL, ",\n");
        }
        printf("\n");

        Vertex v = vertex_init(name, coordenates);
        vector_push(vertexes, v);

        line_size = getline(&line_buf, &line_buf_size, file);
    }

    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;

    /* Close the file now that we are done with it */
    fclose(file);
}