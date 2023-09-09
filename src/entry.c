#include "common.h"
#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

uint32_t g_alreadyStarted = 0;

int __entry(int argc, char** argv)
{
    InitOSFunctionPointers();
	InitVPadFunctionPointers();
	InitGX2FunctionPointers();
	InitSysFunctionPointers();
	InitSocketFunctionPointers();

	if(g_alreadyStarted)
		return 0;

	g_alreadyStarted++;

	init_kernel_syscalls();

	log_init();
	log_printf("\n\n\n---------------[POWERED BY ANOLYNETWORK]---------------\nWiiUHacking by cedkeChat and Azaee\n");
    log_printf("Starting..\n\n");

	return ThreadMenu(argc, argv);
}