#include<iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
using namespace std;

#define NStocks 2518

int main() {
    thrust::device_vector<double> appl_stocks(NStocks);
    thrust::device_vector<double> msft_stocks(NStocks);

    for(int i = 0; i < NStocks; i++) {
        double appl_stock, msft_stock;

        cin >> appl_stock >> msft_stock;

        appl_stocks[i] = appl_stock;
        msft_stocks[i] = msft_stock;
    }

    thrust::device_vector<double> stocks_diff(NStocks);
    thrust::transform(appl_stocks.begin(), appl_stocks.end(), msft_stocks.begin(), stocks_diff.begin(), thrust::minus<double>());

    cout << thrust::reduce(stocks_diff.begin(), stocks_diff.end(), 0, thrust::plus<double>())/NStocks << endl;
    return 0;
}   