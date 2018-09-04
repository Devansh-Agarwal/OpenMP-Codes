// integrating from 0 to 1
//             		4/(1+x^2)dx
# include <iostream>
#include <omp.h>
static long num_steps = 100000000;
double step;
#define NUM_THREADS 4

int main()
{
	double pi =0;
	step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallelOpe
	{
		int i,id, allocatedThreads;
		double x, sum =0;
		id = omp_get_thread_num();
		allocatedThreads = omp_get_num_threads();
		for(i = id; i< num_steps; i+= allocatedThreads)
		{
			x = (i + 0.5)*step;
			sum += 4/(1 + x*x);
		}
		#pragma omp critical
			pi+= sum *step;	
	}
	std::cout << pi << std::endl;
	return 0;
}