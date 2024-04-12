#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quick-union.h"
#include "vector.h"
#include "vertex.h"

int read_file_of_vertexes(FILE* file, Vector vertexes);
// Calcula a distância e armazena na estrtura.

#endif