#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <stdbool.h>
#include <stddef.h>

double *pmt_vec_copy(
    double *restrict dst, const double *restrict src, size_t size);
double *pmt_vec_fill(double *dst, double value, size_t size);

double *pmt_vec_add(double *restrict dst, const double *restrict lhs,
    const double *restrict rhs, size_t size);
double *pmt_vec_add_to(
    double *restrict dst, const double *restrict src, size_t size);
double *pmt_vec_sub(double *restrict dst, const double *restrict lhs,
    const double *restrict rhs, size_t size);
double *pmt_vec_sub_to(
    double *restrict dst, const double *restrict src, size_t size);
double *pmt_vec_scale(double *restrict dst, const double *restrict src,
    double factor, size_t size);
double *pmt_vec_scale_to(double *dst, double factor, size_t size);

#endif
