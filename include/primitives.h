#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <stdbool.h>
#include <stddef.h>

// Define for marking functions as returning a value that must be used
// (for example allocators). Reserved for internal use.
#define __LIBMX_RESULT_FN __attribute__((warn_unused_result))

// Define for marking parts of the API as deprecated. Reserved for internal use.
#define __LIBMX_DEPREC_FN __attribute__((deprecated))

/// \brief Copy the contents of the source buffer to the destination buffer.
double *pmt_vec_copy(
    double *restrict dst, const double *restrict src, size_t size);

/// \brief Fill a buffer with a given value.
double *pmt_vec_fill(double *dst, double value, size_t size);

/// \brief Compute `dst = lhs + rhs`.
double *pmt_vec_add(double *restrict dst, const double *restrict lhs,
    const double *restrict rhs, size_t size);

/// \brief Compute `dst += src`.
double *pmt_vec_add_to(
    double *restrict dst, const double *restrict src, size_t size);

/// \brief Compute `dst = lhs - rhs`.
double *pmt_vec_sub(double *restrict dst, const double *restrict lhs,
    const double *restrict rhs, size_t size);

/// \brief Compute `dst -= src`.
double *pmt_vec_sub_to(
    double *restrict dst, const double *restrict src, size_t size);

/// \brief Compute `dst = src * factor`.
double *pmt_vec_scale(double *restrict dst, const double *restrict src,
    double factor, size_t size);

/// \brief Compute `dst *= factor`.
double *pmt_vec_scale_to(double *dst, double factor, size_t size);

#endif
