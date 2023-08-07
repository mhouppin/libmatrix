#ifndef VECTOR_H
#define VECTOR_H

#include "primitives.h"
#include <assert.h>

/// \brief A structure holding a vector.
typedef struct
{
    /// \brief The number of elements in the vector.
    size_t count;
    /// \brief A pointer to the elements of the vector.
    double *values;
} vector_t;

/// \brief Allocate memory for a vector, keeping its elements uninitialized.
/// \return A positive number if allocation succeeded, zero if no allocation was
/// performed (in the case of zero-dimensional vectors), or a negative value if
/// allocation failed.
/// \warning The return value should be checked for allocation errors!
/// \public \memberof vector_t
int vector_allocate(vector_t *vec, size_t count) __LIBMX_RESULT_FN;

/// \brief Allocate memory for a vector, initializing its elements to zero.
/// \return Same as for vector_allocate().
/// \warning The return value should be checked for allocation errors!
/// \public \memberof vector_t
int vector_init_zero(vector_t *vec, size_t count) __LIBMX_RESULT_FN;

/// \brief Allocate memory for a vector, initializing its elements to the given
/// value.
/// \return Same as for vector_allocate().
/// \warning The return value should be checked for allocation errors!
/// \public \memberof vector_t
int vector_init_from_value(
    vector_t *vec, size_t count, double value) __LIBMX_RESULT_FN;

/// \brief Allocate memory for a vector, initializing its elements with the
/// given array.
/// \return Same as for vector_allocate().
/// \warning The return value should be checked for allocation errors!
/// \public \memberof vector_t
int vector_init_from_array(vector_t *restrict vec, size_t count,
    const double *restrict values) __LIBMX_RESULT_FN;

/// \brief Destroy the memory allocated for the vector, resetting it to a
/// zero-dimensional one.
/// \public \memberof vector_t
void vector_destroy(vector_t *vec);

/// \brief Set the vector elements to the given value.
/// \public \memberof vector_t
vector_t *vector_fill(vector_t *vec, double value);

/// \brief Add src to dst.
/// \public \memberof vector_t
vector_t *vector_add(vector_t *restrict dst, const vector_t *restrict src);

/// \brief Compute the addition of lhs and rhs and store it in dst.
/// \public \memberof vector_t
vector_t *vector_add_to(vector_t *restrict dst, const vector_t *restrict lhs,
    const vector_t *restrict rhs);

/// \brief Subtract src to dst.
/// \public \memberof vector_t
vector_t *vector_sub(vector_t *restrict dst, const vector_t *restrict src);

/// \brief Compute the subtraction of lhs and rhs and store it in dst.
/// \public \memberof vector_t
vector_t *vector_sub_to(vector_t *restrict dst, const vector_t *restrict lhs,
    const vector_t *restrict rhs);

/// \brief Multiply each element in dst by factor.
/// \public \memberof vector_t
vector_t *vector_scale(vector_t *dst, double factor);

/// \brief Compute the scalar multiplication of src by factor and store it in
/// dst.
/// \public \memberof vector_t
vector_t *vector_scale_to(
    vector_t *restrict dst, const vector_t *restrict src, double factor);

/// \brief Compute the linear combination of all the vectors in src using the
/// given coefficients, storing the result in dst. This function assumes that
/// src is an array of vectors.
/// \public \memberof vector_t
vector_t *vector_linear_combine(vector_t *restrict dst,
    const vector_t *restrict src, const vector_t *restrict coeffs);

/// \brief Compute the linear interpolation of dst and src.
/// \public \memberof vector_t
vector_t *vector_lerp(vector_t *restrict dst,
    const vector_t *restrict src, double t);

/// \brief Compute the linear interpolation of lhs and rhs and store it in dst.
/// \public \memberof vector_t
vector_t *vector_lerp_to(vector_t *restrict dst,
    const vector_t *restrict lhs, const vector_t *restrict rhs, double t);

#endif
