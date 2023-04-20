#include "vector.h"

vector_t *vector_sub_to(vector_t *restrict dst, const vector_t *restrict src)
{
    assert(dst->count == src->count);
    pmt_vec_sub_to(dst->values, src->values, dst->count);
    return dst;
}
