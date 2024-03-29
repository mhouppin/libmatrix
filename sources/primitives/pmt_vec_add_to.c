#include "primitives.h"

double *pmt_vec_add_to(double *restrict dst, const double *restrict lhs,
    const double *restrict rhs, size_t size)
{
    for (size_t i = 0; i < size; ++i) dst[i] = lhs[i] + rhs[i];

    return dst;
}
