#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ucontext.h>
#include <unistd.h>
#include "user.h"

int p_spawn(pcb_ll *parent, void* func) {



	// add the inputted function to the context.
	makecontext(&uc, func, 0);

	// context switch.
	setcontext(&uc); //if success, will not return
	perror("setcontext");

	return 0;
}