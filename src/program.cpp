#include "common.h"
#include "program.h"

int MainThread(int argc, void* argv) {
	uint64_t TitleID = OSGetTitleID();
	if(TitleID != 0x00050000101d7500) return 0;

    return 0;
}