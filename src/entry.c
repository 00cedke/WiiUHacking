#include "common.h"

#include "logger.h"
#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

uint32_t g_alreadyStarted = 0;

int __entry(int argc, char **argv) {

	InitOSFunctionPointers();
	InitVPadFunctionPointers();
	InitGX2FunctionPointers();
	InitSysFunctionPointers();
	InitSocketFunctionPointers();

	if(g_alreadyStarted)
		return 0;

	g_alreadyStarted++;

	log_init();
	log_printf("\n\n\n==================\nWiiUHacking by cedkeChat01\n");
	log_printf("https://github.com/00cedke/WiiUHacking/\n\n");

	return InstallerThread(argc, argv);
}
