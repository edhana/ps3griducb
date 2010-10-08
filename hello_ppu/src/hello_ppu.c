#include<stdio.h>
#include<libspe2.h>

extern spe_program_handle_t hello_spu;

int main(void){
	spe_context_ptr_t context;
	
	unsigned int entry = SPE_DEFAULT_ENTRY;
	// initialize context data structure
	context = spe_context_create(0,NULL);
	if (context == NULL) printf("context_create error\n");
	// load executable into the SPE's local store
	if (spe_program_load(context,&hello_spu))
	printf("program_load error\n");
	if (spe_context_run(context,&entry,0,NULL,NULL,NULL) < 0)
	printf("context_run error\n");
	// release associated resources and free memory
	spe_context_destroy(context);
	printf ("Hello world ! PPU\n");	
	
	return 0;
}
