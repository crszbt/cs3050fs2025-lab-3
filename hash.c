//#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

// These are stubs.  That is, you need to implement these functions.

int InsertFailCollision(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
    return 0;
}

void * SearchNoCollision(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
    return NULL;
}


int DivMethod(int key)
{
	int hash = key%7;
	return hash;
}

int MultMethod(int key)
{
	int hash = floor(7*((key*0.7)%1))
    return hash;
}


void * AllocateChainTable(int elementCountMax)
{
    return NULL;
}

void FreeChainTable(void * hashtable)
{
}

int InsertChain(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
    return 0;
}

void * SearchChain(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
    return NULL;
}
