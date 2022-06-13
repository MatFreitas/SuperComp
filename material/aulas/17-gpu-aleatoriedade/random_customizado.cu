#include <thrust/random.h>
#include <thrust/device_vector.h>
#include <thrust/transform.h>
#include <thrust/iterator/counting_iterator.h>
#include <vector>
using namespace std;

struct rng_gpu {
    __device__ __host__
    double operator() (const int &i) {
        thrust::default_random_engine eng(i*10000000);
        thrust::uniform_real_distribution<double> d(25, 40);
        return d(eng);
    }
};

int main() {
    //DENTRO DO PROGRAMA PRINCIPAL, UMA FORMA DE CHAMAR A SUA FUNCAO
    size_t N = 10;
    thrust::device_vector<double> d_random(N);

    thrust::transform(
        thrust::make_counting_iterator<int>(0),
        thrust::make_counting_iterator<int>(N),
        d_random.begin(),
        rng_gpu()
    );

    for(int i = 0; i < N; i++) {
        cout << d_random[i] << endl;
    }

}