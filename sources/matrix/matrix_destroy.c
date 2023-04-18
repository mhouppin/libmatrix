#include "matrix.h"
#include <stdlib.h>

void matrix_destroy(matrix_t *mat)
{
    if (mat->values != NULL)
    {
        free(mat->values);
        mat->values = NULL;
        mat->row_count = 0;
        mat->col_count = 0;
    }
}
