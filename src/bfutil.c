#include<stdio.h>
#include<stdlib.h>
#include"bfutil.h"


//loop pointer operations


/*
add a loop ptr struct to the linked list,
if ptr to null change in place, hence ptr ptr

*/
void add(lptr_t ** arg, uint32_t val){

	lptr_t * new = (lptr_t *)malloc(sizeof(lptr_t));
	new->ip = val;
	new->next= *arg;
	*arg = new;

}


/*
destructor for entire struct as opposed to a single node
*/
void lptr_free(lptr_t * arg){

	if(arg == NULL)
		return;

	lptr_t * cursor = arg->next;
	free(arg);
	lptr_free(cursor);

	//free through the list
}

/*
returns the head value of the linked list 

*/
uint32_t get_head(lptr_t * arg){
	return arg->ip; 
}

uint32_t pop_head(lptr_t ** arg){
	return arg->ip; 
}

//bf_t operations

/*
Initialise the interpreter
and open the file to read

exits with status code 1 if there is an error opening the file
*/
bf_t * bf_init(char * filename){

	//heap allocate the interpreter
	bf_t * ptr = (bf_t *)malloc(sizeof(bf_t));
	
	//attempt to open the file
	ptr->fp = fopen(filename,"r");
	if(!(ptr->fp)){
		fprintf(stderr,"FILE: %s could not be opened.",filename);
		free(ptr);
		exit(1);

	}
	//allocate memory 
	ptr->mem = (char *)malloc(sizeof(char)*30000);
	ptr->lp = NULL;
	return ptr;


}


//frees the memory used by a bf_t
void bf_free(bf_t * arg){


	//add loop ptr freeing
	free(arg->mem);
	fclose(arg->fp);



}
/*
Interprets the brainfuck code pointed to by the file pointer


*/

void bf_interpret(bf_t * arg){
	


}
