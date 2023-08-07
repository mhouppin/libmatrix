#include "matrix.h"

matrix_t *matrix_scale_to(
    matrix_t *restrict dst, const matrix_t *restrict src, double factor)
{
    assert(matrix_same_dimensions(dst, src));
    pmt_vec_scale_to(dst->values, src->values, factor, matrix_size(dst));
    return dst;
}
