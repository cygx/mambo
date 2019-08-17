#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef P5_INT_SIZE
#if   UINTPTR_MAX == UINT32_MAX
#define P5_INT_SIZE 4
#elif UINTPTR_MAX == UINT64_MAX
#define P5_INT_SIZE 8
#else
#error "could not determine int size"
#endif
#endif

#ifndef P5_NUM_SIZE
#define P5_NUM_SIZE 8
#endif

#if P5_NUM_SIZE <= P5_INT_SIZE
#define P5_INLINE_NUM 1
#else
#define P5_INLINE_NUM 0
#endif

#ifndef P5_INT
#define P5_INT intptr_t
#endif

#ifndef P5_UINT
#define P5_UINT uintptr_t
#endif

#ifndef P5_NUM
#define P5_NUM double
#endif

#ifndef P5_SIZE
#define P5_SIZE size_t
#endif

#ifndef P5_SSIZE
#define P5_SSIZE ptrdiff_t
#endif


enum p5_type
{
    P5_TYPE_NULL,

    P5_TYPE_INT_REF,
    P5_TYPE_NUM_INT_REF,
    P5_TYPE_STR,
    P5_TYPE_INVLIST,
    P5_TYPE_STR_INT_REF,
    P5_TYPE_STR_NUM_INT_REF,
    P5_TYPE_FULL_SCALAR,
    P5_TYPE_REGEX,
    P5_TYPE_TYPEGLOB,
    P5_TYPE_DELEGATE,

    P5_COUNT_OF_SCALAR_TYPES,

    P5_TYPE_ARRAY = P5_COUNT_OF_SCALAR_TYPES,
    P5_TYPE_HASH,
    P5_TYPE_SUB,
    P5_TYPE_FORMAT,
    P5_TYPE_IOOBJ,

    P5_COUNT_OF_TYPES,

    P5_TYPE_IV   = P5_TYPE_INT_REF,
    P5_TYPE_RV   = P5_TYPE_INT_REF,
    P5_TYPE_NV   = P5_TYPE_NUM_INT_REF,
    P5_TYPE_PV   = P5_TYPE_STR,
    P5_TYPE_PVIV = P5_TYPE_STR_INT_REF,
    P5_TYPE_PVNV = P5_TYPE_STR_NUM_INT_REF,
};

typedef P5_INT   p5int;
typedef P5_UINT  p5uint;
typedef P5_NUM   p5num;
typedef P5_SIZE  p5size;
typedef P5_SSIZE p5ssize;

typedef enum  p5_type        p5type;
typedef union p5_maybe_magic p5maybe_magic;

typedef union  p5_var    P5Var;
typedef union  p5_scalar P5Scalar;
typedef struct p5_int    P5Int;
typedef struct p5_uint   P5UInt;
typedef struct p5_num    P5Num;
typedef struct p5_str    P5Str;
typedef struct p5_ref    P5Ref;
typedef struct p5_ioobj  P5IOObj;
typedef struct p5_array  P5Array;
typedef struct p5_hash   P5Hash;
typedef struct p5_glob   P5Glob;


typedef struct p5_glob_data  P5GlobData;
typedef struct p5_sub_data   P5SubData;
typedef struct p5_array_data P5ArrayData;
typedef struct p5_hash_data  P5HashData;
typedef struct p5_ioobj_data P5IOObjData;

struct p5_int
{
    P5IntData *data;
    uint32_t refcount;
    uint32_t flags;
    p5int value;
}

struct p5_uint
{
    P5UIntData *data;
    uint32_t refcount;
    uint32_t flags;
    p5uint value;
}

struct p5_ref
{
    P5RefData *data;
    uint32_t refcount;
    uint32_t flags;
    P5Scalar *value;
}

struct p5_num
{
    P5NumData *data;
    uint32_t refcount;
    uint32_t flags;
#if P5_INLINE_NUM
    p5num value;
#endif
}

struct p5_str
{
    P5StrData *data;
    uint32_t refcount;
    uint32_t flags;
    char *value;
}

struct p5_pviv
{};

struct p5_pvnv
{};

struct p5_array
{
    P5ArrayData *data;
    uint32_t refcount;
    uint32_t flags;
    P5Scalar **elements;
}

struct p5_hash
{
    P5HashData *data;
    uint32_t refcount;
    uint32_t flags;
    P5HashEntry **entries;
};

struct p5_glob
{
    P5GlobData *data;
    uint32_t refcount;
    uint32_t flags;
    P5GlobEntry *entry;
};

union p5_scalar
{
    struct {
        void *data;
        uint32_t refcount;
        uint32_t flags;
    };

    P5Int   as_int;
    P5UInt  as_uint;
    P5Num   as_num;
    P5Str   as_str;
    P5Ref   as_ref;
    P5PVIV  as_pviv;
    P5PVNV  as_pvnv;
    P5Glob  as_glob;
};

union p5_var
{
    struct {
        void *data;
        uint32_t refcount;
        uint32_t flags;
    };

    P5Scalar as_scalar;
    P5Array  as_array;
    P5Hash   as_hash;
    P5IOObj  as_ioobj;
    P5Sub    as_sub;
    P5Regex  as_regex;
};

union p5_maybe_magic
{
    P5Magic *magic;
    p5size hash_index;
};

struct p5_hash_data
{
    P5Hash *stash;
    p5maybe_magic maybe_magic;
    p5size keys;
    p5size max;
};

struct p5_ioobj_data
{
};
