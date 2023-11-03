#include "linalg.h"
// double scalar_product(int len, double v1[len], double v2[len]);

double
scalar_product(int len, double v1[len], double v2[len])
{
	//int len = sizeof(v1);
	
	//if(len != sizeof(v2)){
	//	printf("Size of vectors are no-compatible");
	//	exit(1);
	//}
	
	double product = 0;
	
	for(int j = 0; j < len; ++j)
	{
		product += v1[j] * v2[j];
	}
	return product;
}

double *
rng_vector(int len, gsl_rng * r)
{
	double *v = (double *)malloc(sizeof(double)*len);
	
	if (v == NULL){
		perror("malloc failed");
		exit(1);
	}
	
	for(int i = 0; i < len; ++i)
	{
		v[i] = gsl_rng_uniform(r);
		printf ("%.5f\n", v[i]);
	}
	
	return &v;
}

double *
rng_m_n_matrix(int m, int n, gsl_rng * r)
{
	double *mat = (double *)malloc(sizeof(double)*m*n);
	
	if (mat == NULL){
		perror("malloc failed");
		exit(1);
	}
	
	for (int j = 0; j<m; j++)
	{
		mat[j] = (* rng_vector(n, r));
	} 

	return &mat[0];
}
