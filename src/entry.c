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
    log_printf("\n\n\n---------------[POWERED BY ANOLYNETWORK]---------------\nWiiUThreadCpp by cedkeChat and Azaee\n");
    log_printf("STarting Thread..\n\n");

    return Installer(argc, argv);
}