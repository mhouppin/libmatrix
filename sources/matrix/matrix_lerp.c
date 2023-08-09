#include "matrix.h"

matrix_t *matrix_lerp(
    matrix_t *restrict dst, const matrix_t *restrict src, double t)
{
    assert(matrix_same_dimensions(dst, src));
    pmt_vec_scale(dst->values, 1.0 - t, matrix_size(dst));
    pmt_vec_fma(dst->values, src->values, t, matrix_size(dst));
    return dst;
}
