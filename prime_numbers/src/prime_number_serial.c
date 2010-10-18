#include<stdio.h>
#include<math.h>
#include "prime_number_serial.h"
#include "CuTest.h"

/*
 * Array representing the numbers to be evaluated
 */
void find_primes(const int array_size, int number_array[]){

    // Set all but the first element of Array to FALSE
    number_array[0] = FALSE;
    int i = 0;

    for(i = 1; i < array_size; i++){
        number_array[i] = TRUE;
    }

    for(i = 2; i < sqrt(array_size); i++){

        if(number_array[i] == TRUE){
            int j = 0;
            for(j = (i*2); j < array_size; j+=i){ //Vai do primeiro multiplo ao ultimo dentro do limite
                number_array[j] = FALSE;
            }
        }
    }
}

void print_primes(const int array_size, int number_array[]){
    int i = 0;
    
    printf("Imprimindo os primos: ");
    for(i = 0; i < array_size; i++){
        if(number_array[i] == TRUE)
            printf("%d ", i);
    }
    printf("\n", i);
}

