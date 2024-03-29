#pragma once

#include "mem/utils.h"
#include "numbers.h"
#include <sys/sys.h>

/// Exits with a message if `stat` is false.
VORTEX_PREFIX void assert(bool stat, const char *msg) {
    if (!stat) {
        syscall(SYS_write, 3, 1, (usize)msg, strlen(msg));
        syscall(SYS_exit, 1, 1);
    }
}
