#include "CuTest.h"
#include "prime_number_serial.h"

void test_array_length(CuTest *tc){
    int numbers[13];
    CuAssertTrue(tc, array_length(numbers) == 13);
}

void test_set_first_element_false(CuTest *tc){
    int numbers[10];
    find_primes(numbers);
    CuAssertTrue(tc, numbers[0] == FALSE);
}

void test_the_second_element_is_true(CuTest *tc){
    int size = 10;
    int array[size];

    find_primes(array);

    CuAssertTrue(tc, array[1]== TRUE);
}

void test_the_multiples_are_false(CuTest *tc){
    int size = 10;
    int array[size];

    find_primes(array);
    CuAssertTrue(tc, array[4] == FALSE);
}

CuSuite* PrimeNumberGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_set_first_element_false);
    SUITE_ADD_TEST(suite, test_the_second_element_is_true);
    SUITE_ADD_TEST(suite, test_the_multiples_are_false);
    return suite;
}
