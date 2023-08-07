#include "matrix.h"

matrix_t *matrix_sub(matrix_t *restrict dst, const matrix_t *restrict src)
{
    assert(matrix_same_dimensions(dst, src));
    pmt_vec_sub(dst->values, src->values, matrix_size(dst));
    return dst;
}
