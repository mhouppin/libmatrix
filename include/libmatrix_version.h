#ifndef LIBMATRIX_VERSION_H
#define LIBMATRIX_VERSION_H

// Do not use those. Reserved for internal use only.
#define __LIBMATRIX_STR(x) __LIBMATRIX_STR2(x)
#define __LIBMATRIX_STR2(x) #x

#define LIBMATRIX_MAJOR 0
#define LIBMATRIX_MINOR 2
#define LIBMATRIX_PATCH 0

// Conditionally define the pre-release macro, so that people can test for its
// presence at compile-time using a #ifdef.
#define LIBMATRIX_IS_PRERELEASE 0

#if LIBMATRIX_IS_PRERELEASE
#define LIBMATRIX_PRERELEASE ""
#endif

// Runtime checks are possible too in case a shared library is used.
const char *libmatrix_get_version(void);

#endif
