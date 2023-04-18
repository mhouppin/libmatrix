#include "vector.h"
#include <stdlib.h>

void vector_destroy(vector_t *vec)
{
    if (vec->values != NULL)
    {
        free(vec->values);
        vec->values = NULL;
        vec->count = 0;
    }
}
