#include "primitives.h"

double *pmt_vec_fma(double *restrict dst, const double *restrict lhs,
    double factor, const double *restrict rhs, size_t size)
{
    for (size_t i = 0; i < size; ++i) dst[i] = lhs[i] * factor + rhs[i];

    return dst;
}
