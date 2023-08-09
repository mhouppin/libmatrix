#include "matrix.h"

matrix_t *matrix_lerp_to(matrix_t *restrict dst, const matrix_t *restrict lhs,
    const matrix_t *restrict rhs, double t)
{
    assert(matrix_same_dimensions(dst, lhs));
    assert(matrix_same_dimensions(dst, rhs));
    pmt_vec_scale_to(dst->values, lhs->values, 1.0 - t, matrix_size(dst));
    pmt_vec_fma(dst->values, rhs->values, t, matrix_size(dst));
    return dst;
}
