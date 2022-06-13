#include<iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
using namespace std;    

#define NStocks 2518

struct has_increased
{
  __host__ __device__
  bool operator()(const int &x)
  {
    return x > 0;
  }
};

int main() {
    thrust::device_vector<double> stocks(NStocks);
    thrust::device_vector<double> ganho_diario(NStocks);

    for(int i = 0; i < NStocks; i++) {
        double stock;
        cin >> stock;

        stocks[i] = stock;
    }

    thrust::transform(stocks.begin() + 1, stocks.end(), stocks.begin(), ganho_diario.begin(), thrust::minus<double>());
    
    cout << thrust::count_if(ganho_diario.begin(), ganho_diario.end(), has_increased()) << endl;

    
    return 0;
}   