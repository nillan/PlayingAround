#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ucontext.h>
#include <unistd.h>
#include "kernel.h"

#define STACKSIZE 4096;

int k_process_create(pcb_ll *parent) {

	int check = 0;
	PCB *proc;

	if ((proc = malloc(sizeof(PCB))) < 0) {
		perror("malloc");
		return -1;
	}


	// initialize the ucontext.
	getcontext(&(proc->uc));

	// allocate stack space for thread.
	proc->stack = malloc(STACKSIZE);

	proc->uc.uc_stack.ss_sp = proc->stack;
	proc->uc.uc_stack.ss_size = STACKSIZE;
	proc->uc.uc_stack.ss_flags = 0;

	// don't block signals.
	sigemptyset(&(proc->uc.uc_sigmask));

	// no context to switch to after termination.
	proc->uc.uc_link = parent->uc;



}