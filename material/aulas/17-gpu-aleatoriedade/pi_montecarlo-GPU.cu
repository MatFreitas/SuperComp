#include <random>
#include <iostream>
#include <vector>
#include <thrust/random.h>
#include <thrust/device_vector.h>
#include <thrust/transform.h>
#include <thrust/iterator/counting_iterator.h>
using namespace std;

struct rng_gpu {
    __device__ __host__
    double operator() (const int &i) {
        thrust::default_random_engine generator(i*10000000);
        thrust::uniform_real_distribution<double> distribution(0.0, 1.0);
        return distribution(generator);
    }
};

int main () {

    long N = 1000000L;
    long sum = 0;
    thrust::host_vector<double> dotsCPU(2*N);
    thrust::device_vector<double> dots(dotsCPU);

    thrust::transform(
        thrust::make_counting_iterator<int>(0),
        thrust::make_counting_iterator<int>(2*N),
        dots.begin(),
        rng_gpu()
    );
  
   for (long i = 0; i < N; i++) {
        double x, y;
      
        x = dots[i];
        y = dots[2*i];
        if (x*x + y*y <= 1) {
            sum++;
        }
    }
    

    double pi = 4.0 * sum / N;
    cout << pi << endl;
    cout << sum << endl;
  
  }