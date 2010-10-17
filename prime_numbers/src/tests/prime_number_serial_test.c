#include "CuTest.h"
#include "prime_number_serial.h"

void test_set_first_element_false(CuTest *tc){
    int numbers[ARRAY_SIZE][2];
    find_primes(numbers);
    CuAssertTrue(tc, numbers[0][1] == 0);
}

void test_rest_of_elements_is_true(CuTest *tc){
    int array[ARRAY_SIZE][2];
    int i = 0;

    find_primes(array);

    for(i = 1; i < ARRAY_SIZE; i++){
        CuAssertTrue(tc, array[i][1] == 1);
    }
}

CuSuite* PrimeNumberGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_set_first_element_false);
    SUITE_ADD_TEST(suite, test_rest_of_elements_is_true);
    return suite;
}
