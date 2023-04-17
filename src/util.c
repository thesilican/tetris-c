#include "util.h"

Rng rng_new(uint32_t seed)
{
    // Seed cannot be zero
    if (seed == 0)
    {
        seed = 1;
    }
    Rng rng = {.state = seed};
    // Shift the rng a few times to get it started
    for (int i = 0; i < 100; i++)
    {
        rng_next(&rng);
    }
    return rng;
}

uint32_t rng_next(Rng *rng)
{
    rng->state ^= rng->state << 13;
    rng->state ^= rng->state >> 17;
    rng->state ^= rng->state << 5;
    return rng->state;
}