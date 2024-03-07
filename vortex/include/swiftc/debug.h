#pragma once

#include "mem/utils.h"
#include "numbers.h"
#include "os/linux/linux.h"

/// Exits with a message if `stat` is false.
FNDECL_PREFIX void assert(bool stat, const char *msg) {
    if (!stat) {
        SYSCALL(SYS_write, 3, 1, (usize)msg, strlen(msg));
        SYSCALL(SYS_exit, 1, 1);
    }
}
