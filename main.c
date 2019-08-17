#include "moar.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#ifndef NQPLIB
#error "NQPLIB not defined"
#endif

#ifndef BCSIZE
#error "BCSIZE not defined"
#endif

uint8_t MAMBO_BC[BCSIZE];

int main(int argc, char *argv[])
{
#ifndef _WIN32
    signal(SIGPIPE, SIG_IGN);
#endif

    MVMInstance *vm = MVM_vm_create_instance();
    if(argc > 2) MVM_vm_set_clargs(vm, argc - 2, argv + 2);
    MVM_vm_set_prog_name(vm, argc > 1 ? argv[1] : "<repl>");
    MVM_vm_set_exec_name(vm, "mambo");
    MVM_vm_set_lib_path(vm, 1, (const char *[]){ NQPLIB });
    MVM_vm_run_bytecode(vm, MAMBO_BC, sizeof MAMBO_BC);
    MVM_vm_exit(vm);
}
