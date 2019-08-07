#include<stdio.h>
#include<stdlib.h>
#include"bfutil.h"


//loop pointer operations






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
