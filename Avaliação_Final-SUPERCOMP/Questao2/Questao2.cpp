#include<iostream>
#include<random>
#include<omp.h>
#include <iomanip>
#include<vector>
#include<math.h>
using namespace std;

#define MULT 100000

double saxpy(int a, int x, int y) {
    return a * x + y;
}

int main() {
    int n, m, num_threads;

    cin >> n >> m >> num_threads;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    // Multiplicamos por MULT para obter números mais aleatórios
    default_random_engine generator(10*MULT);
    uniform_int_distribution<int> distribution(1, 100000);

    omp_set_num_threads(num_threads);
    #pragma omp parallel shared(generator)
    {
        for(int i = 0; i < n; i++) {
            #pragma omp master
            {
                #pragma omp task 
                {
                    a[i] = distribution(generator);
                }
                #pragma omp task 
                {
                    b[i] = distribution(generator);
                }
            }
        }
    }

    
    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        c[i] = saxpy(m, a[i], b[i]);
    }

    for (int i = 0; i < n; i++ )
        cout << setw(6) << c[i] << " = " 
          << setw(2) << m
          << "*" << setw(5) << a[i]
          << "+" << setw(5) << b[i]
          << endl;


    return 0;
}