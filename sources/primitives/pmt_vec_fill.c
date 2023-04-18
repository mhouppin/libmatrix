#include "primitives.h"

double *pmt_vec_fill(double *dst, double value, size_t size)
{
    for (size_t i = 0; i < size; ++i) dst[i] = value;

    return dst;
}
