#include "vector.h"

vector_t *vector_scale(vector_t *restrict dst, const vector_t *restrict src, double factor)
{
    assert(dst->count == src->count);
    pmt_vec_scale(dst->values, src->values, factor, dst->count);
    return dst;
}
