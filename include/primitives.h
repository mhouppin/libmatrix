#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <stddef.h>

double *pmt_vec_copy(
    double *restrict dst, const double *restrict src, size_t size);
double *pmt_vec_fill(double *dst, double value, size_t size);

#endif
