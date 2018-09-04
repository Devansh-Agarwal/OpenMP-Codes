#include <iostream>
#include <omp.h>
int main()
{
#pragma omp parallel
{
int a =omp_get_thread_num() ;
std::cout << "Hello" << a<< std:: endl;
std::cout << "World,"<< a <<std::endl;
}
return 0;
}
