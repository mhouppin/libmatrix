#include "vector.h"
#include <stdlib.h>

int vector_allocate(vector_t *vec, size_t count)
{
    if (count == 0)
    {
        vec->values = NULL;
        vec->count = 0;
        return 0;
    }

    vec->values = malloc(sizeof(double) * count);
    if (vec->values == NULL)
    {
        vec->count = 0;
        return -1;
    }

    vec->count = count;
    return 1;
}
