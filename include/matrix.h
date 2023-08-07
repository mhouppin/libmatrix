#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

/// \brief A structure holding a matrix.
typedef struct
{
    /// \brief The number of rows in the matrix.
    size_t row_count;
    /// \brief The number of columns in the matrix.
    size_t col_count;
    /// \brief A pointer to the elements of the matrix.
    double *values;
} matrix_t;

/// \brief Return the total number of elements in the matrix.
/// \public \memberof matrix_t
static inline size_t matrix_size(const matrix_t *mat)
{
    return mat->row_count * mat->col_count;
}

/// \brief Test if the matrix is a square matrix.
/// \public \memberof matrix_t
static inline bool matrix_is_square(const matrix_t *mat)
{
    return mat->row_count == mat->col_count;
}

/// \brief Test if both matrixes have identical dimensions.
/// \public \memberof matrix_t
static inline bool matrix_same_dimensions(
    const matrix_t *lhs, const matrix_t *rhs)
{
    return lhs->row_count == rhs->row_count && lhs->col_count == rhs->col_count;
}

/// \brief Allocate memory for a matrix, keeping its elements uninitialized.
/// \return A positive number if allocation succeeded, zero if no allocation was
/// performed (in the case of zero-dimensional matrixes), or a negative value if
/// allocation failed.
/// \warning The return value should be checked for allocation errors!
/// \public \memberof matrix_t
int matrix_allocate(
    matrix_t *mat, size_t row_count, size_t col_count) __LIBMX_RESULT_FN;

/// \brief Allocate memory for a matrix, initializing its elements to zero.
/// \return Same as for matrix_allocate().
/// \warning The return value should be checked for allocation errors!
/// \public \memberof matrix_t
int matrix_init_zero(
    matrix_t *mat, size_t row_count, size_t col_count) __LIBMX_RESULT_FN;

/// \brief Allocate memory for a matrix, initializing its elements to the given
/// value.
/// \return Same as for matrix_allocate().
/// \warning The return value should be checked for allocation errors!
/// \public \memberof matrix_t
int matrix_init_from_value(matrix_t *mat, size_t row_count, size_t col_count,
    double value) __LIBMX_RESULT_FN;

/// \brief Allocate memory for a matrix, initializing its elements with the
/// given array (with all rows being stored contiguously in memory).
/// \return Same as for matrix_allocate().
/// \warning The return value should be checked for allocation errors!
/// \public \memberof matrix_t
int matrix_init_from_array(matrix_t *restrict mat, size_t row_count,
    size_t col_count, const double *restrict values) __LIBMX_RESULT_FN;

/// \brief Destroy the memory allocated for the matrix, resetting it to a
/// zero-dimensional one.
/// \public \memberof matrix_t
void matrix_destroy(matrix_t *mat);

/// \brief Set the matrix elements to the given value.
/// \public \memberof matrix_t
matrix_t *matrix_fill(matrix_t *mat, double value);

/// \brief Add src to dst.
/// \public \memberof matrix_t
matrix_t *matrix_add(matrix_t *restrict dst, const matrix_t *restrict src);

/// \brief Compute the addition of lhs and rhs and store it in dst.
/// \public \memberof matrix_t
matrix_t *matrix_add_to(matrix_t *restrict dst, const matrix_t *restrict lhs,
    const matrix_t *restrict rhs);

/// \brief Subtract src to dst.
/// \public \memberof matrix_t
matrix_t *matrix_sub(matrix_t *restrict dst, const matrix_t *restrict src);

/// \brief Compute the subtraction of lhs and rhs and store it in dst.
/// \public \memberof matrix_t
matrix_t *matrix_sub_to(matrix_t *restrict dst, const matrix_t *restrict lhs,
    const matrix_t *restrict rhs);

/// \brief Multiply each element in dst by factor.
/// \public \memberof matrix_t
matrix_t *matrix_scale(matrix_t *dst, double factor);

/// \brief Compute the scalar multiplication of src by factor and store it in
/// dst.
/// \public \memberof matrix_t
matrix_t *matrix_scale_to(
    matrix_t *restrict dst, const matrix_t *restrict src, double factor);

/// \brief Compute the linear interpolation of dst and src.
/// \public \memberof matrix_t
matrix_t *matrix_lerp(matrix_t *restrict dst,
    const matrix_t *restrict src, double t);

/// \brief Compute the linear interpolation of lhs and rhs and store it in dst.
/// \public \memberof matrix_t
matrix_t *matrix_lerp_to(matrix_t *restrict dst,
    const matrix_t *restrict lhs, const matrix_t *restrict rhs, double t);

#endif
