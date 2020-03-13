#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"
#include "interpreter.h"
#include "ram.h"
#include "cpu.h"
#include "pcb.h"

struct CPU *cpu;
struct PCB *head, *tail;

void addToReady(struct PCB *pcb)
{
//    Here, we add the PCB to the tail of the Ready Queue
	pcb->next = NULL;
	if (tail != NULL)
	{
	    tail->next = pcb;
	    tail = tail->next;
	}
	else
	{
	    head = pcb;
		tail = pcb;
	}
}

void removeFromReady() {
//    Here, we remove the PCB from the Ready Queue
	if (head != NULL)
	{
	    struct PCB *t = head;
	    head = head->next;
	    if (head == NULL)
		    tail = NULL;
	}
	else
	{
	    head = NULL;
		tail = NULL;
	}
}

void myinit(char *filename)
{
    int start, end;
    FILE* p = fopen(filename, "rt");
	if (! p ) // equivalent to saying if ( p == NULL )
    {
        printf("Script not found\n");
    }
    else
    {
//        printf("Reaches myinit functions\n");
	    addToRAM(p, &start, &end);
	    struct PCB *pcb = makePCB(start, end);
	    addToReady(pcb);
	}
}

void scheduler()
{
//    Here, the scheduler function checks if the ready queue is empty.
//    If it is not empty, then control moves into the while loop
    while (head != NULL)
    {
		struct PCB *t = head;
		removeFromReady();

//		It copies the PC from the PCB into the IP of the CPU
		cpu->IP = t->PC;
//		It calls the run(quanta) function within cpu.c to run the script by copying quanta lines of code from ram[] using IP into the IR
		run2(cpu, t->end);

//        If the program is not at the end, then the PCB PC pointer is updated with the IP value
//        Then the PCB is placed at the tail of the ready queue.
		if (cpu->IP >= 0)
		{
		    t->PC = cpu->IP;
			addToReady(t);
		}
		else
		{
//			If the program is at the end, then the PCB terminates
//          We clear the RAM cells, remove the PCB from the Ready queue and call free(PCB) to release C language memory
			clearRAM();
			removeFromReady();
			free(t);
		}
	}
//	Once control reaches this part of the scheduler function, the ready queue is empty
//	This means that all the programs have terminated
//	At this point the exec() function ends, and the user sees the shell command line prompt
}

int main()
{
    head = tail = NULL;
	cpu = (struct CPU*)malloc(sizeof(struct CPU));
//	We need to set the quanta equal to 2 as described in the assignment description
	cpu->quanta = 2;
	shellUI();
}