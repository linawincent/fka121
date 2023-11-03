#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <time.h>
#include "linalg.h"
#include "linalg.c"

int
main( )
{
	int len;

   	printf( "Enter a vector length: ");
   	scanf("%d", &len);
   	
   	printf("Vector length: %i\n", len);
	
	// double *v1 = (double *)malloc(sizeof(double)*len);
	// double *v2 = (double *)malloc(sizeof(double)*len);
	
	const gsl_rng_type * T;
    	gsl_rng * r;
    	gsl_rng_env_setup();
	T = gsl_rng_default;
    	r = gsl_rng_alloc(T);
	time_t seed = time(NULL);
    	gsl_rng_set(r, seed);
    	
    	double *v1 = rng_vector(len, r);
	double *v2 = rng_vector(len, r);

	printf("\nScalar product: %f\n", scalar_product(len, v1, v2));
	
   	return 0;
}



