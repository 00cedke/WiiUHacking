#include "common.h"
#include "program.h"

int MainThread(int argc, void* argv) {
	int title_id = OSGetTitleID();
	if(title_id != 0x00050000101d7500) //Minecraft Title ID
	{
		log_printf("ERROR : Program can't starting games with codes !\n");
		return 0;
	}

	//Your codes

	return 0;
}
