#ifndef PIDLIST_H
#define PIDLIST_H

typedef struct processIDList {

	struct pidList* next;
	struct pidList* prev;
	int pid;

} pidList;

#endif