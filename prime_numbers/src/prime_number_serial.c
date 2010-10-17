#include<stdio.h>
#include<math.h>
#include "prime_number_serial.h"
#include "CuTest.h"

/*
 * Retorna o tamanho de um array
 */
int array_length(int array[]){
    int size = 0;

    size = sizeof(array)/sizeof(int);

    return size;
}

/*
 * Array representing the numbers to be evaluated
 */
void find_primes(int number_array[]){

    // Set all but the first element of Array to FALSE
    number_array[0] = FALSE;
    int i = 0;

    for(i = 1; i < ARRAY_SIZE; i++){
        number_array[i] = TRUE;
        number_array[i] = i;
    }

    for(i = 2; i < sqrt(ARRAY_SIZE); i++){
        printf("Valor de segundo %d\n", i);

        if(number_array[i] == TRUE){
            int j = 0;
            for(j = i; j < ARRAY_SIZE; j+=i){
                number_array[j] = FALSE;
            }
        }
    }
}

