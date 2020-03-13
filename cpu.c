#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"
#include "interpreter.h"
#include "ram.h"
#include "cpu.h"

void run2(struct CPU *cpu, int end)
{
    if(cpu->IP < end)
    {
        int i = 0;
        while(i < cpu->quanta)
	    {
		    if ((cpu->IP) + i != end)
		    {
		        cpu->IR[i] = getFromRAM(cpu->IP + i);
		        i++;
		    }
		    else
		    {
		        break;
		    }
	    }

        int j = 0;
	    while(j < cpu->quanta)
	    {
		    if (cpu->IP != end)
		    {
		        interpret(cpu->IR[j]);
		        cpu->IP++;
		        j++;
		    }
		    else
		    {
			    break;
		    }
	    }
	}
}