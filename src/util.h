#ifndef UTIL_H
#define UTIL_H
#include <stdint.h>

typedef struct Rng
{
    uint32_t state;
} Rng;

Rng rng_new(uint32_t seed);

uint32_t rng_next(Rng *rng);

#endif