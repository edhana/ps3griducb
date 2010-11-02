#include "CuTest.h"
#include "prime_number_serial.h"

void test_set_first_element_false(CuTest *tc){
    const int size = 10;    
    int numbers[size];
    find_primes(size, numbers);
    CuAssertTrue(tc, numbers[0] == FALSE);
}

void test_the_second_element_is_true(CuTest *tc){
    const int size = 10;
    int array[size];

    find_primes(size, array);

    CuAssertTrue(tc, array[1]== TRUE);
}

void test_the_third_element_is_true(CuTest *tc){
    const int size = 10;
    int array[size];

    find_primes(size, array);

    CuAssertTrue(tc, array[2]== TRUE);
}

void test_the_multiples_are_false(CuTest *tc){
    const int size = 10;
    int array[size];

    find_primes(size, array);
    CuAssertTrue(tc, array[4] == FALSE);
    //print_primes(size, array);
}

void test_the_long_prime_are_false(CuTest *tc){
    const int size = 2610000;
    int array[size];

    find_primes(size, array);
/*    CuAssertTrue(tc, array[4] == FALSE);*/
/*    print_primes(size, array);*/
}

CuSuite* PrimeNumberGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_set_first_element_false);
    SUITE_ADD_TEST(suite, test_the_second_element_is_true);
    SUITE_ADD_TEST(suite, test_the_third_element_is_true);
    SUITE_ADD_TEST(suite, test_the_multiples_are_false);
    SUITE_ADD_TEST(suite, test_the_long_prime_are_false);
    return suite;
}
