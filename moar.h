#include <stdint.h>
#include <atomic_ops.h>
#include <moar/types.h>

#define MVM_PUBLIC
#define MVM_STATIC_INLINE static inline

typedef int8_t   MVMint8;
typedef uint8_t  MVMuint8;
typedef int16_t  MVMint16;
typedef uint16_t MVMuint16;
typedef int32_t  MVMint32;
typedef uint32_t MVMuint32;
typedef int64_t  MVMint64;
typedef uint64_t MVMuint64;
typedef float    MVMnum32;
typedef double   MVMnum64;

#include <moar/6model/6model.h>
