#include "matrix.h"

matrix_t *matrix_add(matrix_t *restrict dst, const matrix_t *restrict src)
{
    assert(matrix_same_dimensions(dst, src));
    pmt_vec_add(dst->values, src->values, matrix_size(dst));
    return dst;
}
