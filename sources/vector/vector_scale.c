#include "vector.h"

vector_t *vector_scale(vector_t *dst, double factor)
{
    pmt_vec_scale(dst->values, factor, dst->count);
    return dst;
}
