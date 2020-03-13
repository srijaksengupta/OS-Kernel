#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

char *ram[1000];


char *getFromRAM(int cell)
{
	return ram[cell];
}

void addToRAM(FILE *p, int *start, int *end)
{
    char buffer[1000];

    int i = 0;
    for(i=0;i<1000;i++)
    {
        if(ram[i] == NULL)
        {
            break;
        }
    }

	int x = i;
	int start_cell = x;

    fgets(buffer, 999, p);
    while (!feof(p) && x < 999)
    {
		if (ram[x] != NULL)
		{
			fclose(p);
			exit(1);
		}
		ram[x] = strdup(buffer);
		x++;
		fgets(buffer, 999, p);
	}
	*start = start_cell;
	*end = x;

    fclose(p);
}

void clearRAM()
{
    for(int i=0;i<1000;i++)
    {
        ram[i] = NULL;
    }
}