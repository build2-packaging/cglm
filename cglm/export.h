#pragma once

#if defined(CGLM_STATIC)         /* Using static. */
#  define CGLM_SYMEXPORT
#elif defined(CGLM_STATIC_BUILD) /* Building static. */
#  define CGLM_SYMEXPORT
#elif defined(CGLM_SHARED)       /* Using shared. */
#  ifdef _WIN32
#    define CGLM_SYMEXPORT __declspec(dllimport)
#  else
#    define CGLM_SYMEXPORT
#  endif
#elif defined(CGLM_SHARED_BUILD) /* Building shared. */
#  ifdef _WIN32
#    define CGLM_SYMEXPORT __declspec(dllexport)
#  else
#    define CGLM_SYMEXPORT
#  endif
#else
/* If none of the above macros are defined, then we assume we are being used
 * by some third-party build system that cannot/doesn't signal the library
 * type. Note that this fallback works for both static and shared libraries
 * provided the library only exports functions (in other words, no global
 * exported data) and for the shared case the result will be sub-optimal
 * compared to having dllimport. If, however, your library does export data,
 * then you will probably want to replace the fallback with the (commented
 * out) error since it won't work for the shared case.
 */
#  define CGLM_SYMEXPORT         /* Using static or shared. */
/*#  error define CGLM_STATIC or CGLM_SHARED preprocessor macro to signal cglm library type being linked */
#endif
