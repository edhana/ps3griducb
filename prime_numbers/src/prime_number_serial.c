#include<stdio.h>
/*#include<math.h>*/
#include "prime_number_serial.h"
#include "CuTest.h"

#define ARRAY_SIZE 10

/*
 * number_array[x][0] = The Number
 * number_array[x][1] = True or false if it is a prime number
 */
void find_primes(int number_array[][2]){
    // Set all but the first element of Array to FALSE
    number_array[0][1] = 0;
    int i = 0;
    for(i = 1; i < ARRAY_SIZE; i++){
        number_array[i][1] = 1;
    }
}

