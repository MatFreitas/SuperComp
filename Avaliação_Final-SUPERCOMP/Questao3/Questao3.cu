#include <random>
#include <iostream>
#include <vector>
#include <thrust/random.h>
#include <thrust/device_vector.h>
#include <thrust/transform.h>
#include <thrust/iterator/counting_iterator.h>
using namespace std;

struct is_one
{
  __host__ __device__
  bool operator()(const int &x)
  {
    return x & 1;
  }
};

struct square 
{
    __device__ __host__
    double operator()(const double &x) {
        return x*x;
    }
};

struct rng_gpu {
    __device__ __host__
    double operator() (const int &i) {
        thrust::default_random_engine generator(i*10000000);
        thrust::uniform_real_distribution<double> distribution(0.0, 1.0);
        return distribution(generator);
    }
};

int main () {

    long N = 100000000L;
    thrust::host_vector<double> dotsCPU(2*N);
    thrust::device_vector<double> dots(dotsCPU);
    
    thrust::transform(
        thrust::make_counting_iterator<int>(0),
        thrust::make_counting_iterator<int>(2*N),
        dots.begin(),
        rng_gpu()
    );

    thrust::transform(
        dots.begin(),
        dots.end(),
        dots.begin(),
        square()
    );

    thrust::device_vector<double> squareSum(N);
    thrust::transform(
        dots.begin(),
        dots.begin() + N/2,
        dots.begin() + N/2 + 1,
        squareSum.begin(),
        thrust::plus<double>()  
    );

    thrust::constant_iterator<double> one(1.0);
    thrust::device_vector<double> lessEqual(N);
    thrust::transform(
        squareSum.begin(),
        squareSum.end(),
        one,
        lessEqual.begin(),
        thrust::less_equal<double>()
    );

    
    int result = thrust::count_if(
        lessEqual.begin(),
        lessEqual.end(),
        is_one()
    );

    cout << 4.0 * result/N;

    
  
  }