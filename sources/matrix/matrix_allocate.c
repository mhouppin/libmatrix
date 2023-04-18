#include "matrix.h"
#include <stdlib.h>

int matrix_allocate(matrix_t *mat, size_t row_count, size_t col_count)
{
    if (row_count == 0 || col_count == 0)
    {
        mat->row_count = row_count;
        mat->col_count = col_count;
        mat->values = NULL;
        return 0;
    }

    size_t size = row_count * col_count;

    if (size / row_count != col_count)
    {
        mat->row_count = 0;
        mat->col_count = 0;
        mat->values = NULL;
        return -1;
    }

    mat->values = malloc(sizeof(double) * size);

    if (mat->values == NULL)
    {
        mat->row_count = 0;
        mat->col_count = 0;
        return -1;
    }

    mat->row_count = row_count;
    mat->col_count = col_count;
    return 1;
}
