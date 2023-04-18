#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct matrix_s
{
    size_t row_count;
    size_t col_count;
    double *values;
} matrix_t;

static inline size_t matrix_size(const matrix_t *mat)
{
    return mat->row_count * mat->col_count;
}

int matrix_init_zero(matrix_t *mat, size_t row_count, size_t col_count);
int matrix_init_from_value(
    matrix_t *mat, size_t row_count, size_t col_count, double value);
int matrix_init_from_array(matrix_t *restrict mat, size_t row_count,
    size_t col_count, const double *restrict values);
int matrix_allocate(matrix_t *mat, size_t row_count, size_t col_count);
void matrix_destroy(matrix_t *mat);

matrix_t *matrix_fill(matrix_t *mat, double value);

#endif
