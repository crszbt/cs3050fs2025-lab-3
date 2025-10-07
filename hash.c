//#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

// These are stubs.  That is, you need to implement these functions.

int InsertFailCollision(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
	int hash = HashFunc(key); //gets the hash based on the inputted key
	if(*(hashtable+(elementSize*hash))!=NULL || hash>elementCountMax) //if that hash is unavailable...
	{
		return -1; //returns -1
	}
	else
	{
		hashtable+(elementSize*hash) = element; //places the element in the proper address location in the hash table
	}
    return 0; //returns 0 if no errors are present
}

void * SearchNoCollision(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
	int hash = HashFunc(key); //gets the hash based on the inputted key
	if(*(hashtable+(elementSize*hash))!=NULL) //if there is an element at that hash...
	{
		return *(hashtable+(elementSize*hash)); //returns the element at the propor hash
	}
    return NULL;
}


int DivMethod(int key)
{
	int hash = key%13;
	return hash;
}

int MultMethod(int key)
{
	double a = 0.6180339887
	int hash = 128*((key*a)-(int)(key*a));
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
