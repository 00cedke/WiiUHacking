#include "libs.hpp"
#include "kernel.hpp"
#include "thread.h"

int MainThread(int argc, void* argv) {
	uint64_t TitleID = OSGetTitleID();
    //Minecraft Title.
	if(TitleID != 0x00050000101d7500) return 0;

    //Code Here
	
	return 0;
}