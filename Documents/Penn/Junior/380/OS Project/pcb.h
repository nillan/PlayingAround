#ifndef PCB_H
#define PCB_H
#include <ucontext.h>

typedef struct processControlBlock {

	ucontext_t uc;
	int pid;
	int parentPid;
	pidList childPid;
	int pgid;
	//signal handler variable
	int status;
	int[2] fd;
	int priority;
	pidList zombie;
	int initTime;
	void *stack;

} PCB;


#endif