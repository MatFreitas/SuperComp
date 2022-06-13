#include <iostream>
#include <unistd.h>
#include<omp.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

double funcao1() {
    sleep(4);
    return 47;
}

double funcao2() {
    sleep(1);
    return -11.5;
}

int main() {
    auto start = high_resolution_clock::now();

    double res_func1, res_func2;

    #pragma omp parallel 
    {
        #pragma omp master
        {
            std::cout << "só roda uma vez na thread:" << omp_get_thread_num() << "\n";
            #pragma omp task
            {
                std::cout << "Estou rodando na thread:" << omp_get_thread_num() << "\n";
                res_func1 = funcao1();
            }
            #pragma omp task
            {
                std::cout << "Estou rodando na thread:" << omp_get_thread_num() << "\n";
                res_func2 = funcao2();
            }
        }
    }

    std::cout << res_func1 << " " << res_func2 << "\n";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}
