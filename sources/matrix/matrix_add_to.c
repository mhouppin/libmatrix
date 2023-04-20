#include "matrix.h"

matrix_t *matrix_add_to(matrix_t *restrict dst, const matrix_t *restrict src)
{
    assert(matrix_same_dimensions(dst, src));
    pmt_vec_add_to(dst->values, src->values, matrix_size(dst));
    return dst;
}
