#ifndef RAM_H
#define RAM_H

char *getFromRAM(int cell);
void addToRAM(FILE *p, int *start, int *end);
void clearRAM();

#endif