#include "matrix.h"

matrix_t *matrix_fill(matrix_t *mat, double value)
{
    pmt_vec_fill(mat->values, value, matrix_size(mat));
    return mat;
}
