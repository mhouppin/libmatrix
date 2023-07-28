#include "primitives.h"

double *pmt_vec_fma_to(double *restrict dst, const double *restrict src,
    double factor, size_t size)
{
    for (size_t i = 0; i < size; ++i) dst[i] += src[i] * factor;

    return dst;
}
