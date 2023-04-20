#include "matrix.h"

matrix_t *matrix_sub_to(matrix_t *restrict dst, const matrix_t *restrict src)
{
    assert(matrix_same_dimensions(dst, src));
    pmt_vec_sub_to(dst->values, src->values, matrix_size(dst));
    return dst;
}
