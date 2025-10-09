#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

// These are stubs.  That is, you need to implement these functions.

int InsertFailCollision(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
	//for some reason, all keys turn to 0 at this point
	int hash = HashFunc(key); //gets the hash based on the inputted key
	void* testmem;
	testmem = calloc(1,elementSize); //creates an empty memory space to compare the hashes to
	if(memcmp((hashtable+(elementSize*hash)), testmem, elementSize)!=0) //if that hash is unavailable...
	{
		free(testmem);
		return -1; //returns -1
	}
	else
	{
		memcpy(element,(hashtable+(elementSize*hash)),elementSize); //places the element in the proper address location in the hash table
	}	
	free(testmem);
    return 0; //returns 0 if no errors are present
}

void * SearchNoCollision(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
	int hash = HashFunc(key); //gets the hash based on the inputted key
	return (hashtable+(elementSize*hash)); //returns the element at the propor hash
}


int DivMethod(int key)
{
	int hash = key%TABLESIZE;
	return hash;
}

int MultMethod(int key)
{
	double a = 0.6180339887;
	int hash = TABLESIZE*((key*a)-(int)(key*a));
    return hash;
}

typedef struct //creates struct for linked list
{
void* data; //void pointer to store data
int key;
void* next; //void pointer to store next link
}Link;

void * AllocateChainTable(int elementCountMax)
{
	Link ** hashtable; //creates has table
	hashtable = malloc(elementCountMax*sizeof(Link*));//allocates space for hash table
	for(int i=0;i<elementCountMax;i+=sizeof(Link*)) //for every space in the table...
	{
		(*(hashtable+i)) = malloc(sizeof(Link)); //creates empty link to occupy that space
		(*(hashtable+i))->data = NULL; //defaults data to null
		(*(hashtable+i))->next = NULL; //defaults next to null
		(*(hashtable+i))->key = -1; //defaults key to -1
	}
    return (void*)hashtable; //returns finished hash table
}

void FreeChain(Link* link)
{
	if(link->next != NULL) //if this link isn't the end of the chain...
	{
		FreeChain(link->next); //frees next link first
	}
	free(link); //frees link
}

void FreeChainTable(void * hashtable)
{
	Link ** chainarray = (Link**)hashtable; //creates new pointer to hash table of type Link**
	for(int i=0;i<TABLESIZE;i+=sizeof(Link*)) //for every chain in the list...
	{
		FreeChain(*(chainarray+i)); //frees chain
	}
	free(hashtable); //frees original pointer;
}

int InsertChain(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
	Link ** chainarray = (Link**)hashtable; //creates new pointer to hash table of type Link**
	int hash = HashFunc(key); //gets hash from key
	if((*(chainarray+hash*elementSize))->data == NULL) //if that space is empty...
	{
		(*(chainarray+hash*elementSize))->data = element; //put data there
		(*(chainarray+hash*elementSize))->key = key; //list key
	}
	else
	{
		Link* newlink = malloc(sizeof(Link)); //creates a new pointer to a link
		Link* emptyspace = malloc(sizeof(Link)); //creates a new space for a link
		newlink->data = element; //sets the data in the new link to element
		newlink->key = key; //sets the key of the new link to key
		memcpy(emptyspace, *(chainarray+hash*elementSize), sizeof(Link)); //stores the previous head of the chain in the empty space
		memcpy(*(chainarray+hash*elementSize), newlink, sizeof(Link)); //moves the new link to be the new head of the chain
		free(newlink); //frees the previous space where the new link was
		(*(chainarray+hash*elementSize))->next = emptyspace; //sets the next element after the new link to the previous head of the chain
	}
    return 0; //returns 0
}

void * SearchChain(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
	int hash = HashFunc(key); //gets the hash based on the inputted key
	Link ** chainarray = (Link**)hashtable; //creates new pointer to hash table of type Link**
	if((*(chainarray+hash*elementSize))->data == NULL) //if that space is empty...
	{
		return NULL; //return null
	}
	else
	{
		Link* i = (*(chainarray+hash*elementSize)); //creates iterator
		while(i!=NULL) //while iterator is not null
		{
			if(i->key == key) //check if the key matches
			{
				return i->data; //if so, return the data at that link
			}
			else //if not...
			{
				i = i->next; //check the next link
			}
		}
		return NULL; //if the data is not found somehow, return null
	}
}
