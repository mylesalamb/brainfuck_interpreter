#ifndef BFUTIL_GUARD
#define BFUTIL_GUARD
#include <stdint.h>
#include <stdio.h>

typedef struct loop_pointer {

struct loop_pointer* next;
uint32_t ip;

} lptr_t;


typedef struct bfstruct {

	uint32_t ip; //current instruction
	FILE * fp; //ptr to the currently open file
	char * mem;  //array of memory locations
	lptr_t * lp; //linked list of loop indexes

} bf_t;


bf_t * bf_init(char * filename);






#endif