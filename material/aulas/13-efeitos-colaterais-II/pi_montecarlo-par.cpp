#include<iostream>
#include<random>
#include<omp.h>
using namespace std;

#define N 100000

int main() {
    double sum = 0.0;
    double init_time, final_time;
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);
    init_time = omp_get_wtime();

    omp_set_num_threads(4);
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < N; i++) {
        #pragma omp critical
        {
            default_random_engine generator(i);
            uniform_real_distribution<double> distribution(0.0, 1.0);
            double x = distribution(generator);
            double y = distribution(generator);
            if(x*x + y*y <= 1) {
                sum++;
            }
        }
    }

    cout << 4 * sum / N << endl;

    final_time = omp_get_wtime() - init_time;

    std::cout  << final_time << " secs\n";
    return 0;
}