#include<iostream>
#include<omp.h>
#include <math.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

#define N 1000000000

int main() {
    auto start = high_resolution_clock::now();

    float result = 0;

    #pragma omp parallel for
    for(int i = 0; i < N; i++) {
        result += pow(-1, i)/(2*i + 1);
    }

    cout << result << endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
         
    return 0;
}