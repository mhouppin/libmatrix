#include "matrix.h"

int matrix_init_from_value(
    matrix_t *mat, size_t row_count, size_t col_count, double value)
{
    int retval = matrix_allocate(mat, row_count, col_count);

    if (retval > 0) matrix_fill(mat, value);

    return retval;
}
