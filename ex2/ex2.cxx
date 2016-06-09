//
// compute pi from the integral 4/(1 + x^2) from 0 to 1
// from https://www.youtube.com/watch?v=nE-xN4Bf8XI
//
// alexander at gokliya dot net

#ifdef HAVE_OPENMP
#include <omp.h>
#endif

#include <cstdlib>
#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
    int numSteps = atoi(argv[1]);
    double dx = 1.0 / numSteps;
    double sum = 0;
    
#ifdef HAVE_OPENMP
#pragma omp parallel
{
    int id = omp_get_thread_num();
    int nth = omp_get_num_threads();
    if (id == 0) {
        std::cout << "Running with " << nth << " threads\n";
    }
}
#endif

#pragma omp reduction (+:sum)
    for (int i = 0; i < numSteps; ++i ) {
        double x = (i + 0.5)*dx;
        sum += dx * 4. / (1. + x*x);
    }

    std::cout << "approx pi = " << sum << " error = " << M_PI - sum << '\n';
}
