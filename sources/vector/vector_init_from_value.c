#include "vector.h"

int vector_init_from_value(vector_t *vec, size_t count, double value)
{
    int retval = vector_allocate(vec, count);

    if (retval > 0) vector_fill(vec, value);

    return retval;
}
