#include "vector.h"

vector_t *vector_fill(vector_t *vec, double value)
{
    pmt_vec_fill(vec->values, value, vec->count);
    return vec;
}
