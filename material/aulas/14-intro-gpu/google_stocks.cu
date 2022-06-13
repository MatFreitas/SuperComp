#include<iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
using namespace std;

int main() {
    thrust::host_vector<double> stocks;

    for(int i = 0;i < 2518; i++) {
        double stock;
        cin >> stock;
        stocks.push_back(stock);    
    }

    thrust::device_vector<double> stocks_GPU(stocks);

    // Percorrendo vetor maneira simples
    // for(int i = 0; i < int(stocks_GPU.size()); i++) {
    //     cout << stocks_GPU[i] << endl;
    // }

    cout << "Média nos últimos 10 anos: " << thrust::reduce(stocks_GPU.begin(), stocks_GPU.end(), 0, thrust::plus<double>())/int(stocks_GPU.size()) << endl;
    cout << "Média no último ano: " << thrust::reduce(stocks_GPU.end() - 365, stocks_GPU.end(), 0, thrust::plus<double>())/365 << endl;
    return 0;
}   