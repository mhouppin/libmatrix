#include "vector.h"

vector_t *vector_lerp(
    vector_t *restrict dst, const vector_t *restrict src, double t)
{
    assert(dst->count == src->count);
    pmt_vec_scale(dst->values, 1.0 - t, dst->count);
    pmt_vec_fma(dst->values, src->values, t, dst->count);
    return dst;
}
