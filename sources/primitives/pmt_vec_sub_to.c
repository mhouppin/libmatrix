#include "primitives.h"

double *pmt_vec_sub_to(
    double *restrict dst, const double *restrict src, size_t size)
{
    for (size_t i = 0; i < size; ++i) dst[i] -= src[i];

    return dst;
}
