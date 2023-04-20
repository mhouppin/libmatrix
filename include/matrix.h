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

static inline bool matrix_is_square(const matrix_t *mat)
{
    return mat->row_count == mat->col_count;
}

static inline bool matrix_same_dimensions(const matrix_t *lhs, const matrix_t *rhs)
{
    return lhs->row_count == rhs->row_count && lhs->col_count == rhs->col_count;
}

int matrix_init_zero(matrix_t *mat, size_t row_count, size_t col_count);
int matrix_init_from_value(
    matrix_t *mat, size_t row_count, size_t col_count, double value);
int matrix_init_from_array(matrix_t *restrict mat, size_t row_count,
    size_t col_count, const double *restrict values);
int matrix_allocate(matrix_t *mat, size_t row_count, size_t col_count);
void matrix_destroy(matrix_t *mat);

matrix_t *matrix_fill(matrix_t *mat, double value);

matrix_t *matrix_add(matrix_t *restrict dst, const matrix_t *restrict lhs, const matrix_t *restrict rhs);
matrix_t *matrix_add_to(matrix_t *restrict dst, const matrix_t *restrict src);
matrix_t *matrix_sub(matrix_t *restrict dst, const matrix_t *restrict lhs, const matrix_t *restrict rhs);
matrix_t *matrix_sub_to(matrix_t *restrict dst, const matrix_t *restrict src);
matrix_t *matrix_scale(matrix_t *restrict dst, const matrix_t *restrict src, double factor);
matrix_t *matrix_scale_to(matrix_t *dst, double factor);

#endif
