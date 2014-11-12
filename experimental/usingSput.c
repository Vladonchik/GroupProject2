//
// usingSput.c
// Created by bclarke on 2014/08/11
// tags: 
//
/*---------- Standard Headers -----------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*---------- Custom Headers	-----------*/

#include ".headers/debug.h"
#include ".headers/sput.h"
#include ".headers/usingSput.h"
#include ".headers/sputFunctions.h"

/*---------- Main -----------*/
void testPrimeTrue();
void testPrimesFalse();
int prime(int number, int divisor);
void primeTesting();

int main(int argc, char *argv[]){

	primeTesting();
	return sput_get_return_value();
}

void primeTesting()	{
	sput_start_testing(); /*! \brief prepares everything Sput needs.*/
	sput_set_output_stream(NULL); /*! \brief sets where output should go.  NULL is stdoutput.*/
	/*! \brief entering new suite.  This should be done for every set of tests.  Choose name arbitrarily inside brackets*/
	sput_enter_suite("test_prime_true(): All Primes"); 
	sput_run_test(testPrimeTrue); /*! \brief running test.  Pass name of your test function without () to run via sput.*/
	sput_leave_suite(); /*! \brief when you are going to start a new suite.*/

	sput_enter_suite("testPrimesFalse(): No Primes");	
	sput_run_test(testPrimesFalse);
	sput_leave_suite();
	/*! \brief when you are done with sput.*/
	sput_finish_testing();
}

/*---------- Functions ----------*/

int prime(int number, int divisor)	{
	if(divisor == number) { return 1; }
	if(number%divisor == 0)	{ return 0; }

	return prime(number, divisor + 1);
}

void testPrimeTrue() {

	ActionQueueStructure validPrimes = createActionQueue(1);

	FILE *fp;
	int number;

	fp = fopen(".text/validPrime.txt","r");

	while(fscanf(fp,"%d",&number) != EOF) {
		pushToQueue(validPrimes, number);
		/*! \brief KEY sput line.  Says that the test will fail UNLESS output from called function is 1.*/
		sput_fail_unless(prime(popFromQueue(validPrimes),2) == 1, "vaild prime");
	}
 
	fclose(fp);

}

void testPrimesFalse()	{


	ActionQueueStructure invalidPrimes = createActionQueue(1);
	int number;
	FILE *fp;
	fp = fopen(".text/notValidPrime.txt","r");
	while(fscanf(fp,"%d",&number) != EOF) {
		pushToQueue(invalidPrimes,number);
		/*! \brief KEY sput line.  Says that the test will fail UNLESS output from called function is 0.*/
		sput_fail_unless(prime(popFromQueue(invalidPrimes),2) == 0, "invalid prime");
	}
	fclose(fp);
}
