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
	sput_start_testing(); //prepares everything Sput needs.
	//sets where output should go.  NULL is stdoutput.
	sput_set_output_stream(NULL);
	
	sput_enter_suite("test_prime_true(): All Primes");
	sput_run_test(testPrimeTrue);
	sput_leave_suite();

	sput_enter_suite("testPrimesFalse(): No Primes");	
	sput_run_test(testPrimesFalse);
	sput_leave_suite();

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
		sput_fail_unless(prime(popFromQueue(invalidPrimes),2) == 0, "invalid prime");
	}
	fclose(fp);
}
