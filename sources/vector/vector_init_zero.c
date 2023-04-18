#include "vector.h"

int vector_init_zero(vector_t *vec, size_t count)
{
    return vector_init_from_value(vec, count, 0.0);
}
