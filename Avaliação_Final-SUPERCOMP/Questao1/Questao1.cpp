#include<iostream>
#include<random>
#include<omp.h>
#include<math.h>
using namespace std;

#define MULT 100000

int main() {
    int N, num_threads;
    double sum = 0.0;

    cin >> N;
    vector<int> vec(N, 0);

    cin >> num_threads;

    omp_set_num_threads(num_threads);
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < N; i++) {
        #pragma omp critical
        {
            // Multiplicamos por MULT para obter números mais aleatórios
            default_random_engine generator(i*MULT);
            uniform_int_distribution<int> distribution(1, 199);
            vec[i] = distribution(generator); 
            sum += vec[i];
        }
    }

   for(int i = 0; i < N; i++) {
    cout << vec[i] << endl;
   }

   double mean = sum/N;
   double var = 0.0;

   #pragma omp parallel for reduction(+:var)
   for(int i = 0; i < N; i++) {
    var += pow(vec[i] - mean, 2);
   }

   var /= N;

   cout << "Média: " << mean << endl;
   cout << "Variância: " << var << endl;
   
    return 0;
}