#include "common.h"
#include <string.h>
#include <malloc.h>
#include "program.h"
#include "main.h"

extern "C" int InstallerThread(int argc, char** argv) {

	uint8_t *stack = (uint8_t*)memalign(0x10, 0x1000);
	OSThread *thread = (OSThread*)memalign(0x10, 0x1000);

	bool ret = OSCreateThread(thread, MainThread, 0, NULL, (uint32_t)stack + 0x1000, 0x1000, 0, ((1 << 2) | 8 | 16));
	if(!ret)
	{
		os_sleep(2);
		return 0;
	}

	log_printf("===[WiiUHacking by cedkeChat01]===");
	OSSetThreadName(thread, "WiiUHackingThread");
	OSResumeThread(thread);

	return -3;
}
