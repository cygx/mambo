#include <stdint.h>
#include <atomic_ops.h>
#include <moar/types.h>

#define MVM_PUBLIC __declspec(dllimport)
#define MVM_NO_RETURN _Noreturn
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

MVM_PUBLIC MVMInstance * MVM_vm_create_instance(void);
MVM_PUBLIC void MVM_vm_run_file(MVMInstance *instance, const char *filename);
MVM_PUBLIC void MVM_vm_run_bytecode(MVMInstance *instance, MVMuint8 *bytes, MVMuint32 size);
MVM_PUBLIC MVM_NO_RETURN void MVM_vm_exit(MVMInstance *instance);
MVM_PUBLIC void MVM_vm_destroy_instance(MVMInstance *instance);
MVM_PUBLIC void MVM_vm_set_clargs(MVMInstance *instance, int argc, char **argv);
MVM_PUBLIC void MVM_vm_set_exec_name(MVMInstance *instance, const char *exec_name);
MVM_PUBLIC void MVM_vm_set_prog_name(MVMInstance *instance, const char *prog_name);
MVM_PUBLIC void MVM_vm_set_lib_path(MVMInstance *instance, int count, const char **lib_path);
