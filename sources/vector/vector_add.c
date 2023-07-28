#include "vector.h"

vector_t *vector_add(vector_t *restrict dst, const vector_t *restrict lhs,
    const vector_t *restrict rhs)
{
    assert(dst->count == lhs->count);
    assert(dst->count == rhs->count);
    pmt_vec_add(dst->values, lhs->values, rhs->values, dst->count);
    return dst;
}
