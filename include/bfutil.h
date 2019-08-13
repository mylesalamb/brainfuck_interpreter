#ifndef BFUTIL_GUARD
#define BFUTIL_GUARD
#include <stdint.h>
#include <stdio.h>

//loop pointer stuff

typedef struct loop_pointer {

	struct loop_pointer* next;
	uint32_t ip;

} lptr_t;

void add(lptr_t ** arg,uint32_t val);
void lptr_free(lptr_t * arg);
uint32_t get_head(lptr_t * arg);
uint32_t pop_head(lptr_t ** arg);


//intepreter stuff

typedef struct bfstruct {

	uint32_t ip; //current instruction
	FILE * fp; //ptr to the currently open file
	uint32_t dp; //data pointer
	char * mem;  //array of memory locations
	lptr_t * lp; //linked list of loop indexes

} bf_t;


bf_t * bf_init(char * filename);
void bf_free(bf_t * arg);
void bf_interpret(bf_t * arg);






#endif