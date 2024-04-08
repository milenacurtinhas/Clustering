#include "reading.h"
#include "vertex.h"
#include <stdio.h>
#include <unistd.h>

void read_file(const char* filename, Vector vertexes)
{
    Vector coordenates = vector_init(50, sizeof(double));
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size = 0;
    FILE *file = fopen(filename, "r");
    if (!file){
        printf("ERROR: couldn't find the file given!\n");
    }

    /* Loop through until we are done with the file. */
    Vertex A;
    int id=0;

    while (line_size >= 0)
    {
        line_size = getline(&line_buf, &line_buf_size, file);

        /* Show the line details */
        //printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s", line_count, line_size, line_buf_size, line_buf);
            char * name = strdup(strtok(line_buf, ",s"));
            printf("(%d) %s : ", id, name);
            int i = 0;
            char * ptr;
            /*while (line_buf != NULL){
                //char * number_char = strtok(line_buf, ",");
                double number = strtod("5.09393", ptr);
                vector_push_at(coordenates, &number, i);
                printf("%lf   ,   ", number);
            }*/
          printf("\n");
            //A = vertex_init(name, id, coordenates);
            //vector_push(vertexes, A);
            free(name);
        id++;
        /* Increment our line count */
        line_count++;
        /* Get the next line */
        //line_size = getline(&line_buf, &line_buf_size, file);
    }

    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;
    vector_destroy(coordenates);

    /* Close the file now that we are done with it */
    fclose(file);
}