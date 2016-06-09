
#include <omp.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
// compute pi from the integral 4/(1 + x^2) from 0 to 1

int main(int argc, char** argv) {

    if (argc < 2) {
      std::cerr << "Need number of steps\n";
      std::cerr << argv[0] << " <numSteps>\n";
      std::exit(1);
    }
    int numSteps = atoi(argv[1]);
    double dx = 1.0 / numSteps;
    int numThreads = 0;
    
#pragma omp parallel
{
    int id = omp_get_thread_num();
    int nth = omp_get_num_threads();
    if (id == 0) {
        // store the number of threads in shared variable
        numThreads = nth;
    }
}
    std::cout << "number of threads: " << numThreads << '\n';
    double partialSums[numThreads];
    double sum = 0.0;
#pragma omp parallel
{
    int id = omp_get_thread_num();
    partialSums[id] = 0;
    for (int i = id; i < numSteps; i += numThreads) {
        double x = (i + 0.5)*dx;
        partialSums[id] += dx * 4. / (1. + x*x);
    }
#pragma omp atomic 
    sum += partialSums[id];
}
    std::cout << "approx pi = " << sum << " error = " << M_PI - sum << '\n';

    return 0;
}
