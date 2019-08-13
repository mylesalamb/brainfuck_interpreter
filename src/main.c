#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bfutil.h"
#define STRSIZE 100
int main(int argc,  char * const argv[])
{
	int arg;
	int hflag = 0;
	char filename[STRSIZE];
	

while((arg  = getopt(argc,argv,"hf:"))!= -1)
	switch(arg){
		case 'h':
			hflag = 1;
			break;
		case 'f':
			strcpy(filename,optarg);
			break;
	}

	if(hflag){
		printf("usage: -f FILENAME\n");
		return 0;
	}

	printf("Starting interpreter with filename: %s\n",filename );
	bf_t * interp = bf_init(filename);
	bf_interpret(interp);
	bf_free(interp);



	return 0;
}