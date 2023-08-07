#include "vector.h"

vector_t *vector_linear_combine(vector_t *restrict dst,
    const vector_t *restrict src, const vector_t *restrict coeffs)
{
    if (coeffs->count == 0) return dst;

    assert(dst->count == src->count);
    pmt_vec_scale_to(dst->values, src->values, coeffs->values[0], dst->count);

    for (size_t i = 1; i < coeffs->count; ++i)
    {
        assert(dst->count == (src + i)->count);
        pmt_vec_fma(
            dst->values, (src + i)->values, coeffs->values[i], dst->count);
    }

    return dst;
}
