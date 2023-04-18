#include "matrix.h"

int matrix_init_zero(matrix_t *mat, size_t row_count, size_t col_count)
{
    return matrix_init_from_value(mat, row_count, col_count, 0.0);
}
