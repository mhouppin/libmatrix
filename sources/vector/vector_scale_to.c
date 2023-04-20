#include "vector.h"

vector_t *vector_scale_to(vector_t *dst, double factor)
{
    pmt_vec_scale_to(dst->values, factor, dst->count);
    return dst;
}
