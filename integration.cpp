// integrating from 0 to 1
//             		4/(1+x^2)dx
# include <iostream>
#include <omp.h>
static long num_steps = 100000000;
double step;
#define NUM_THREADS 10

int main()
{
	int i, nthreads;
	double pi, sum[NUM_THREADS];
	step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallelOpe
	{
		int i, id, allocatedThreads;
		double x;
		id = omp_get_thread_num();
		allocatedThreads = omp_get_num_threads();
		if(id == 0)
			nthreads = allocatedThreads;
		for(i = id,sum[id] = 0; i< num_steps; i+= allocatedThreads)
		{
			x = (i + 0.5)*step;
			sum[id]+= 4/(1 + x*x);
		}
	}
	for(i = 0, pi =0;i < nthreads; i++)
		pi += sum[i]*step;
	std::cout << pi << std::endl;
	return 0;
}