#include "common.h"
#include "program.h"

int MainThread(int argc, void* argv) {
    uint64_t title_id = OSGetTitleID();
    if (title_id != 0x00050000101d7500)
    {
	log_printf("error for starting program.");
	return 0;    
    } 

    return 0;
}
