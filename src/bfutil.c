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
	lptr_t * cursor = *arg;
	uint32_t val = cursor->ip;
	*arg = (*arg)->next;
	free(cursor);
	return val;



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
	ptr->ip=0;
	ptr->dp = 0;

	//allocate memory 
	ptr->mem = (char *)calloc(sizeof(char),30000);
	ptr->lp = NULL;
	return ptr;


}


//frees the memory used by a bf_t
void bf_free(bf_t * arg){

	free(arg->mem);
	fclose(arg->fp);
	lptr_free(arg->lp);
	free(arg);



}
/*
Interprets the brainfuck code pointed to by the file pointer
returning output (if any to stdout)

reading input from stdin
*/

void bf_interpret(bf_t * arg){

	char c;

	printf("Program out\n############################################\n");

	while( (c=fgetc(arg->fp)) != EOF ){

		//printf("IP: %d C:%c DP: %d mem[DP]:%d \n",arg->ip,c,arg->dp,(arg->mem)[arg->dp]);

		switch(c){
			case '+':
				(arg->mem)[arg->dp]++;
				break;

			case '-':
				(arg->mem)[arg->dp]--;
				break;

			case'>':
				(arg->dp)++;
				break;

			case '<':
				(arg->dp)--;
				break;

			case '[':
				add(&(arg->lp),arg->ip);
				break;

			case ']':
				if ((arg->mem)[arg->dp]==0)
				{
					pop_head(&(arg->lp));
				}
				else{
					//look back to correct point in the file
					arg->ip = get_head(arg->lp)+1;
					fseek(arg->fp,arg->ip,SEEK_SET);
					continue;
				}
				break;

			case '.':
				putchar((arg->mem)[arg->dp]);
				break;

			case ',':
				(arg->mem)[arg->dp] = getc(stdin);
				break; 
		}

		(arg->ip)++;

	}

	printf("############################################\n");
	
}
