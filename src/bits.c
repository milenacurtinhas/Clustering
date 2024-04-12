#include "bits.h"

Bits bits(int N) {
    int size = ceil((N + 1) / 8.0);
    Bits bits = (Bits)calloc(sizeof(Bits), size);
    return bits;
}

void bits_set(Bits bits, int pos, bool value) {
    if (value) {
        int pos_char = pos / 8;
        unsigned char cmp = 1 << pos % 8;
        bits[pos_char] = bits[pos_char] | cmp;
    } else {
        int pos_char = pos / 8;
        unsigned char cmp = 1 << pos % 8;
        bits[pos_char] = bits[pos_char] ^ cmp;
    }
}

bool bits_get(Bits bits, int pos) {
    int pos_char = pos / 8;
    unsigned char cmp = 1 << pos % 8;
    int result = cmp & bits[pos_char];
    return result;
}

void bits_destroy(Bits bits) {
    free(bits);
}
