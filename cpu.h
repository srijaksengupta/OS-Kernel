#ifndef CPU_H
#define CPU_H

struct CPU
{
	int IP;
	char *IR[1000];
	int quanta;
};

void run2(struct CPU *cpu, int end);

#endif