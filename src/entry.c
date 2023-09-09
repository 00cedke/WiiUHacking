#include "libs.hpp"
#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

int __entry(int argc, char** argv)
{
    InitOSFunctionPointers();
    InitSocketFunctionPointers();
    InitGX2FunctionPointers();

    log_init();
    log_print("ThreadCpp by cedkeChat and Azaee..\n");

    return Installer(argc, argv);
}