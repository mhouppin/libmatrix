#include "vector.h"

vector_t *vector_sub(vector_t *restrict dst, const vector_t *restrict src)
{
    assert(dst->count == src->count);
    pmt_vec_sub(dst->values, src->values, dst->count);
    return dst;
}
