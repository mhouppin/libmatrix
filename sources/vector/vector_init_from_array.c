#include "vector.h"

int vector_init_from_array(
    vector_t *restrict vec, size_t count, const double *restrict values)
{
    int retval = vector_allocate(vec, count);

    if (retval > 0) pmt_vec_copy(vec->values, values, count);

    return retval;
}
