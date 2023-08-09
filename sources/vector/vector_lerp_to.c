#include "vector.h"

vector_t *vector_lerp_to(vector_t *restrict dst, const vector_t *restrict lhs,
    const vector_t *restrict rhs, double t)
{
    assert(dst->count == lhs->count);
    assert(dst->count == rhs->count);
    pmt_vec_scale_to(dst->values, lhs->values, 1.0 - t, dst->count);
    pmt_vec_fma(dst->values, rhs->values, t, dst->count);
    return dst;
}
