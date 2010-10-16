#include<stdio.h>
#include<libspe2.h>
#include<pthread.h>

/*
 * E necessaria a criacao de uma nova funcao para controlar
 * o contexto das spus
 *
 */
void *ppu_pthread_function(void *arg){
    spe_context_ptr_t context = *(spe_context_ptr_t *) arg;
    unsigned int entry = SPE_DEFAULT_ENTRY;
    spe_context_run(context, &entry, 0, NULL, NULL, NULL);
    pthread_exit(NULL);
}

extern spe_program_handle_t hello_spu;

int main(void){
	spe_context_ptr_t context;
	pthread_t pthread;

	context = spe_context_create(0,NULL);

    spe_program_load(context, &hello_spu);

    pthread_create(&pthread, NULL, &ppu_pthread_function, &context);

    pthread_join(pthread, NULL);
    spe_context_destroy(context);
    printf("Hello World! PPU\n");
    return 0;
}
