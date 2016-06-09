#include <omp.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
// compute pi from the integral 4/(1 + x^2) from 0 to 1

int main(int argc, char** argv) {
    int numSteps = atoi(argv[1]);
    double dx = 1.0 / numSteps;
    double sum = 0;
    
#pragma omp parallel
{
    int threadId = omp_get_thread_num();
    int numThreads = omp_get_num_threads();
    if (threadId == 0) std::cout << "Running with " << numThreads << " threads\n";
}
#pragma omp reduction (+:sum)
    for (int i = 0; i < numSteps; ++i ) {
        double x = (i + 0.5)*dx;
        sum += dx * 4. / (1. + x*x);
    }

    std::cout << "approx pi = " << sum << " error = " << M_PI - sum << '\n';
}