#include "matrix.h"

matrix_t *matrix_scale(matrix_t *dst, double factor)
{
    pmt_vec_scale(dst->values, factor, matrix_size(dst));
    return dst;
}
