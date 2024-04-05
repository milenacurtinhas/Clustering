#include "reading.h"
#include "vertex.h"
#include <stdio.h>
#include <unistd.h>


void read_file(const char* filename)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    FILE *file = fopen(filename, "r");
    if (!file){
        printf("ERROR: couldn't find the file given!\n");
    }

      /* Get the first line of the file. */
    line_size = getline(&line_buf, &line_buf_size, file);

    /* Get the first line of the file. */
    line_size = getline(&line_buf, &line_buf_size, file);

    /* Loop through until we are done with the file. */
    //Vertex A;
    int id=0;
    while (line_size >= 0)
    {
        /* Increment our line count */
        line_count++;

        /* Show the line details */
        printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s", line_count,
            line_size, line_buf_size, line_buf);
            //char *name = strtok(line_buf, ",");
            // while (line_buf != NULL){
            //     printf("name: %s //// id: %d, //// coord: %s\n",name, id, strtok(line_buf, ","));

            // }
            //A = vertex_init(name, id, A_coord);
        id++;
        /* Get the next line */
        line_size = getline(&line_buf, &line_buf_size, file);
    }

    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;

    /* Close the file now that we are done with it */
    fclose(file);
}