#include "libs.hpp"
#include <kernel/kernel_utils.h>
#include <kernel/kernel_defs.h>
#include <kernel/syscalls.h>
#include <libutils/system/memory.h>
#include <libutils/kernel/syscalls.h>
#include <libutils/kernel/kernel_utils.h>

void init_kernel_syscalls();

void SC0x25_KernelCopyData(u32 addr, u32 src, u32 len);