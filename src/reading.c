#include "reading.h"
#include "vertex.h"
#include <unistd.h>


int line_dimensity(char *line){
    int result = 0;

    while(*line != '\0'){
        if(*line == ','){
            result++;
        }
        line++;
    }

    return result;
}


void read_file(const char* filename, Vector vertexes)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    ssize_t line_size = 0;

    FILE *file = fopen(filename, "r");
    if (!file){
        printf("ERROR: couldn't find the file given!\n");
    }

    /* Loop through until we are done with the file. */
    line_size = getline(&line_buf, &line_buf_size, file);
    int n = line_dimensity(line_buf);

    while (line_size >= 0)
    {
        double *coordenates = calloc(n, sizeof(double));
        char * name = strdup(strtok(line_buf, ",\n"));

        char *ptr, *number_char = strtok(NULL, ",\n");
        int i = 0;
        while (number_char != NULL){
            double number = strtod(number_char, &ptr);
            coordenates[i] = number;

            i++;
            number_char = strtok(NULL, ",\n");
        }

        Vertex v = vertex_init(name, coordenates);
        //double *coord = vertex_get_coordinates(v);

        //printf("%s: %lf, %lf\n", vertex_get_name(v), coord[0], coord[1]);

        vector_push(vertexes, &v);

        line_size = getline(&line_buf, &line_buf_size, file);
    }


    /* Free the allocated line buffer */
    free(line_buf);

    /* Close the file now that we are done with it */
    fclose(file);
}