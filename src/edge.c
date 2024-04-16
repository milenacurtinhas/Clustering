#include "edge.h"

int edge_cmp(const void *a, const void *b) {
    const EdgeStruct *aa = (const EdgeStruct *)a;
    const EdgeStruct *bb = (const EdgeStruct *)b;

    double diff = aa->dist - bb->dist;
    
    if (diff > 0)
        return 1;
    else
        return -1;
}