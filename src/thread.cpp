#include "common.h"
#include "thread.h"

int MainThread(int argc, void* argv) {
	if(OSGetTitleID() != 0x0005000010113400)
	{
		log_printf("tkt zebi\n");
		return 0;
	}

	/*
	*	YOUR CODE HERE
	*/

	return 0;
}