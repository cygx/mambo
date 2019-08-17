#include "moar.h"
#include "perl5.h"

typedef struct p11_var P11Var;
typedef P5Var P11VarBody;

typedef struct p11_int P11Int;
typedef p5int P11IntBody;

typedef struct p11_object_ref P11ObjectRef;
typedef MVMObject *P11ObjectRefBody;

// main type
struct p11_var
{
    MVMObject common;
    P11VarBody body;
};

// native type
struct p11_int
{
    MVMObject common;
    P11IntBody body;
};

// reference to a generic 6model object
struct p11_object_ref
{
    MVMObject common;
    P11ObjectRefBody body;
};
