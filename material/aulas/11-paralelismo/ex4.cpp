#include <iostream>
#include<omp.h>

using namespace std;

int main(){

    int N = 100;
    int nthreads, tid, idx;
    float a[N], b[N], c[N];

    // a thread de numero zero é chamada de master
    // so a thread zero entra aqui
    #pragma omp parallel master
    {
        nthreads = omp_get_thread_num();
        cout << "Numero de threads = " << nthreads << endl;
    }

    // cada uma vai inicializar o vetor com 1
    #pragma omp parallel for
    for(idx = 0; idx < N; idx++){
        a[idx] = b[idx] = 1.0;
    }

    // calcula a soma dos dois vetores
    #pragma omp parallel for private(tid)
    for(idx = 0; idx < N; idx++){
        c[idx] = a[idx] + b[idx];
        tid = omp_get_thread_num();
        cout << "Thread " << tid << ", c[" << idx << "] =" << c[idx] << endl;
    }

    return 0;
}