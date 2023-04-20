#include "vector.h"

vector_t *vector_sub(vector_t *restrict dst, const vector_t *restrict lhs, const vector_t *restrict rhs)
{
    assert(dst->count == lhs->count);
    assert(dst->count == rhs->count);
    pmt_vec_sub(dst->values, lhs->values, rhs->values, dst->count);
    return dst;
}
