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

typedef struct //creates struct for linked list
{
void* data;
int key;
void* next = NULL;
}Link;

void * AllocateChainTable(int elementCountMax)
{
	void* hashtable; //creates hash table
	hashtable = malloc(elementCountMax*sizeof(void*)); //allocates space for hash table
    return hashtable;
}

void FreeChainTable(void * hashtable)
{
	void * nexthash = hashtable->next; //creates pointer to the next hash down the chain
	if(nexthash!=NULL)
	{
		FreeChainTable(nexthash); //frees next hash
	}
	free(hashtable); //frees current hash;
}

int InsertChain(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
	int hash = HashFunc(key); //gets the hash based on the inputted key
	if(hash>elementCountMax) //if that hash is nonexistent...
	{
		return -1; //returns -1
	}
	if(*(hashtable+(elementSize*hash))!=NULL) //if that hash is occupied...
	{
		void * i = (*(hashtable+(elementSize*hash))); //creates iterator to travel down chain
		while (i->next != NULL)
			{
				i = i->next;
			}
		Link * newlink = malloc(sizeof(Link)); //allocates space for new chain link
		newlink->data = element; //stores element data in new chain link
		newlink->next = NULL;
		newlink->key = key; //gives new chain correct key
		i->next = newlink; //adds new link to the chain
	}
	else
	{
		Link * newlink = malloc(sizeof(Link)); //allocates space for new chain link
		newlink->data = element; //stores element data in new chain link
		newlink->next = NULL;
		newlink->key = key; //gives new chain correct key
		*(hashtable+(elementSize*hash)) = newlink; //adds first link to the chain
	}
    return 0; //returns 0 if no errors are present
}

void * SearchChain(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
	int hash = HashFunc(key); //gets the hash based on the inputted key
	if(*(hashtable+(elementSize*hash))!=NULL) //if there is an element at that hash...
	{
		void * i = (*(hashtable+(elementSize*hash))); //creates iterator to travel chain
		while(i->key != key) //iterates down chain until the propor key is found
			{
				i = i->next;
			}
		return i->data; //returns the element at the propor hash
	}
    return NULL;
}
