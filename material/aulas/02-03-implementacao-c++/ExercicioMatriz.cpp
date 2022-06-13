#include<iostream>
#include<vector>
#include<chrono>
#include<math.h>
#include<cmath>
using namespace std;
using namespace std::chrono;

void calcula_distancia(vector<vector<double>> &matriz, vector<double> &x, vector<double> &y) {
    int n = x.size();
    for(int i = 0; i < n; i++) {
        vector<double> linha;
        for(int j = 0; j < n; j++) {
            double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            linha.push_back(dist);
        }
        matriz.push_back(linha);
    }
}

int main() {
    auto start = high_resolution_clock::now();

    int n;

    cin >> n;

    vector<double> x, y;
    x.reserve(n);
    y.reserve(n);
    for(int i = 0; i < n; i++) {
        double xt, yt;
        cin >> xt;
        cin >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }

    vector<vector<double>> D;
    calcula_distancia(D, x, y);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}