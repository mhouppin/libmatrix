#include "matrix.h"

matrix_t *matrix_scale_to(matrix_t *dst, double factor)
{
    pmt_vec_scale_to(dst->values, factor, matrix_size(dst));
    return dst;
}
