#include "common.h"
#include <string.h>
#include <malloc.h>
#include "program.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <wups.h>
#include <nsysnet/nssl.h>
#include <coreinit/cache.h>
#include <coreinit/dynload.h>
#include <coreinit/mcp.h>
#include <coreinit/memory.h>
#include <coreinit/memorymap.h>
#include <coreinit/memexpheap.h>

WUPS_PLUGIN_NAME("WiiUHacking");
WUPS_PLUGIN_DESCRIPTION("WiiUHacking Aroma");
WUPS_PLUGIN_VERSION("v2.0");
WUPS_PLUGIN_AUTHOR("cedkeChat01");
WUPS_PLUGIN_LICENSE("ISC");

#include <kernel/kernel.h>
#include <mocha/mocha.h>

static OSDynLoad_Module olv_handle;

extern "C" void QuickTextDisplay(const char *text)
{
	OSScreenInit();
	OSScreenEnableEx(1, 1);
	OSScreenClearBufferEx(1, 0);
	OSScreenSetBufferEx(1, (void*)0xF4000000);
	OSScreenPutFontEx(1, 0, 0, text);
	OSScreenFlipBuffersEx(1);
}

extern "C" int InstallerThread() {

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

INITIALIZE_PLUGIN() {
    WHBLogUdpInit();
    auto res = Mocha_InitLibrary();

    if (res != MOCHA_RESULT_SUCCESS) {
        DEBUG_FUNCTION_LINE("Mocha init failed with code %d!", res);
        return;
    }

    InstallerThread();

    DEBUG_FUNCTION_LINE("WiiUHacking worked successfully !");
}

DEINITIALIZE_PLUGIN() {
    WHBLogUdpDeinit();
    Mocha_DeinitLibrary();
}

ON_APPLICATION_START() {
    WHBLogUdpInit();

    DEBUG_FUNCTION_LINE("WiiUHacking: WAAAAAAAAAAAAAAAAA!\n");

    OSDynLoad_Acquire("nn_olv", &olv_handle);
    DEBUG_FUNCTION_LINE("WiiUHacking: olv! %08x\n", olv_handle);
}

ON_APPLICATION_ENDS() {
    DEBUG_FUNCTION_LINE("WiiUHacking: shutting down...\n");
    OSDynLoad_Release(olv_handle);
}
