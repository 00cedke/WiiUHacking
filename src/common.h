#pragma once

#include <gctypes.h>
#include <libutils/utils/logger.h>
#include <libutils/system/memory.h>
#include <libutils/kernel/syscalls.h>
#include <libutils/kernel/kernel_utils.h>
#include <dynamic_libs/os_functions.h>
#include <dynamic_libs/gx2_functions.h>
#include <dynamic_libs/vpad_functions.h>
#include <dynamic_libs/sys_functions.h>
#include <dynamic_libs/socket_functions.h>

#define RETURN_TO_HBL 			(0)
#define RETURN_TO_NEXT_APP 		(-3)