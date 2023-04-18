#include "matrix.h"

int matrix_init_from_array(matrix_t *restrict mat, size_t row_count,
    size_t col_count, const double *restrict values)
{
    int retval = matrix_allocate(mat, row_count, col_count);

    if (retval > 0) pmt_vec_copy(mat->values, values, matrix_size(mat));

    return retval;
}
