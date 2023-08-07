#include "primitives.h"

double *pmt_vec_scale(double *dst, double factor, size_t size)
{
    for (size_t i = 0; i < size; ++i) dst[i] *= factor;

    return dst;
}
