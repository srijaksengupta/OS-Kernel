#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "pcb.h"

struct PCB *makePCB(int start, int end)
{
//    Here, we create a PCB instance using malloc
	struct PCB *pcb = (struct PCB *)malloc(sizeof(struct PCB));
	pcb->PC = start;
	pcb->start = start;
	pcb->end = end;
	pcb->next = NULL;
	return pcb;
}