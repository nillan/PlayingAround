#ifndef PCB_LL_H
#define PCB_LL_H

struct list_el {

	PCB *pcb;
	struct list_el *next;

};

typedef struct list_el pcb_ll;



#endif