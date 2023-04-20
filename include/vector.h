#ifndef VECTOR_H
#define VECTOR_H

#include <assert.h>
#include "primitives.h"

typedef struct vector_s
{
    size_t count;
    double *values;
} vector_t;

int vector_init_zero(vector_t *vec, size_t count);
int vector_init_from_value(vector_t *vec, size_t count, double value);
int vector_init_from_array(
    vector_t *restrict vec, size_t count, const double *restrict values);
int vector_allocate(vector_t *vec, size_t count);
void vector_destroy(vector_t *vec);

vector_t *vector_fill(vector_t *vec, double value);

vector_t *vector_add(vector_t *restrict dst, const vector_t *restrict lhs, const vector_t *restrict rhs);
vector_t *vector_add_to(vector_t *restrict dst, const vector_t *restrict src);
vector_t *vector_sub(vector_t *restrict dst, const vector_t *restrict lhs, const vector_t *restrict rhs);
vector_t *vector_sub_to(vector_t *restrict dst, const vector_t *restrict src);
vector_t *vector_scale(vector_t *restrict dst, const vector_t *restrict src, double factor);
vector_t *vector_scale_to(vector_t *dst, double factor);

#endif
