#include "common.h"
#include "thread.h"

int MainThread(int argc, void* argv) {
	int title_id = OSGetTitleID();
	if(title_id != 0x00050000101d7500) //Minecraft Title ID
	{
		log_printf("tkt zebi\n");
		log_printf("error to load your game\n");
		return 0;
	}

	//Your code

	return 0;
}