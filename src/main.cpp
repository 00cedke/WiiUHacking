#include "libs.hpp"
#include "main.h"
#include "thread.h"

#define OS_THREAD_ATTR_AFFINITY_NONE    0x0007u        // affinity to run on every core
#define OS_THREAD_ATTR_AFFINITY_CORE0   0x0001u        // run only on core0
#define OS_THREAD_ATTR_AFFINITY_CORE1   0x0002u        // run only on core1
#define OS_THREAD_ATTR_AFFINITY_CORE2   0x0004u        // run only on core2
#define OS_THREAD_ATTR_DETACH           0x0008u        // detached
#define OS_THREAD_ATTR_PINNED_AFFINITY  0x0010u        // pinned (affinitized) to a single core
#define OS_THREAD_ATTR_CHECK_STACK_USE  0x0040u        // check for stack usage
#define OS_THREAD_ATTR_NAME_SENT        0x0080u  	   //tkttttttttttttttttttt zebi

extern "C" int Installer(int argc, char** argv) {
	//Loading..
	log_print("Starting..\n");

	uint8_t *stack = (uint8_t*)MEM2_alloc(0x1000, 0x10);
	OSThread *thread = (OSThread*)MEM2_alloc(0x1000, 0x10);

	bool ret = OSCreateThread(thread, MainThread, 0, NULL, (uint32_t)stack + 0x1000, 0x1000, 0, ((1 << 2) | 8 | 16));
	if(!ret)
	{
		log_printf("Error create thread\n");
		os_sleep(2);
		return 0;
	}

	if(OSGetTitleID() == 0x000500101004A100 || OSGetTitleID() == 0x000500101004A000 || OSGetTitleID() == 0x000500101004A200)
	{
		SYSLaunchMenu();
		return -3;
	}

	OSSetThreadName(thread, "WiiUThreadGame");
	OSResumeThread(thread);

	return -3;

}
