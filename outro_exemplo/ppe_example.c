/*
 Exemplo retirado de http://cellprogramming.wordpress.com/

In order to compile the sources the following commands are needed.

spu-gcc spe_program.c -o spe_program

ppu-embedspu Vec_Test_SPU spe_program lib_spu_program.a

ppu-gcc ppe_program.c lib_spu_program.a -lspe2 -o ppe_program
*/

#include <stdio.h>
#include <stdlib.h>
#include <libspe2.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>

typedef struct {
unsigned int id_spe   __attribute__ ((aligned (16)));
} context;

extern spe_program_handle_t Vec_Test_SPU;

typedef struct ppu_pthread_data {
spe_context_ptr_t spe_ctx;
pthread_t pthread;
unsigned int entry;
void *argp;
} ppu_pthread_data_t;

void *ppu_pthread_function(void *arg)
{
ppu_pthread_data_t *datap = (ppu_pthread_data_t *)arg;
if (spe_context_run(datap->spe_ctx, &datap->entry, 0, datap->argp, NULL, NULL) < 0)
{
perror (“Failed running context\n”);
exit (1);
}
pthread_exit(NULL);
}

ASD
const unsigned int MAX_SPE_THREADS = 8;

int main()
{

ppu_pthread_data_t datas[MAX_SPE_THREADS];
context ctxs[MAX_SPE_THREADS] __attribute__ ((aligned (16)));

//Obtenemos el número de hilos a crear
unsigned int spe_threads = spe_cpu_info_get(SPE_COUNT_USABLE_SPES, -1);
if (spe_threads > MAX_SPE_THREADS)
spe_threads = MAX_SPE_THREADS;

unsigned int i;
// Create multiple SPE threads
for (i=0; i<spe_threads; i++) {

// Create SPE context
if ((datas[i].spe_ctx = spe_context_create (0, NULL)) == NULL) {
perror (“Failed creating context”);
exit (1);
}
// Load SPE program into the SPE context
if (spe_program_load (datas[i].spe_ctx, &Vec_Test_SPU)) {
perror (“Failed loading program”);
exit (1);
}
// Initialize context run data
datas[i].entry = SPE_DEFAULT_ENTRY;
datas[i].argp = &ctxs[i];

// Create pthread for each of the SPE conexts
if (pthread_create (&datas[i].pthread, NULL, &ppu_pthread_function,
&datas[i])){
perror (“Failed creating thread”);
}
}
// Wait for all the SPE threads to complete.
for (i=0; i<spe_threads; i++) {
if (pthread_join (datas[i].pthread, NULL)) {
perror (“Failed joining thread”);
exit (1);
}
}

printf(“FIN PPU\n”);

return (0);
}
