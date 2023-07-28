#include "libmatrix_version.h"

// clang-format off
const char *libmatrix_get_version(void)
{
    return __LIBMX_STR(LIBMATRIX_MAJOR)
        "." __LIBMX_STR(LIBMATRIX_MINOR)
        "." __LIBMX_STR(LIBMATRIX_PATCH)
#if LIBMATRIX_IS_PRERELEASE
        "-" __LIBMX_STR(LIBMATRIX_PRERELEASE)
#endif
        ;
}
// clang-format on
