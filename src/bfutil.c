#include<stdio.h>
#include<stdlib.h>
#include"bfutil.h"

/*
Initialise the interpreter
and open the file to read

exits with status code 1 if there is an error opening the file
*/
bf_t * bf_init(char * filename){

	bf_t * ptr = (bf_t *)malloc(sizeof(bf_t));
	ptr->fp = fopen(filename,"r");
	if(!ptr->fp){
		fprintf(stderr,"FILE: %s could not be opened.",filename);
		free(ptr);
		exit(1);

	}
	ptr->mem = (char *)malloc(sizeof(char)*30000);
	return ptr;


}
