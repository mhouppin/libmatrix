#include "matrix.h"

matrix_t *matrix_sub(matrix_t *restrict dst, const matrix_t *restrict lhs,
    const matrix_t *restrict rhs)
{
    assert(matrix_same_dimensions(dst, lhs));
    assert(matrix_same_dimensions(dst, rhs));
    pmt_vec_sub(dst->values, lhs->values, rhs->values, matrix_size(dst));
    return dst;
}
