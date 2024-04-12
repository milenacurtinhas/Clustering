#ifndef BITS_H
#define BITS_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char* Bits;

Bits bits(int N);
void bits_set(Bits bits, int pos, bool value);
bool bits_get(Bits bits, int pos);
void bits_destroy(Bits bits);

#endif